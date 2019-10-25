#include "Header.h"

#if !ABANDONED_CODE
/*
 *				abandoned
 *
 *
 */
int cost_function(real_t *in_x, real_t *in_u) {
    int i, j;

    // X: 8x1
    // U: 2x1
    real_t in_x_e[8];
    real_t in_u_e[2];
    pb_vars.costs = 0;

    /*
     *			k	=	0
     *			in_x_e =
     */
    for (i = 0; i < 8; i++) in_x_e[i] = in_x[i] - pb_vars.x_des[i];

    for (j = 0; j < 2; j++) in_u_e[i] = in_u[i];

    for (i = 0; i < 8; i++) pb_vars.costs += in_x_e[i] * in_x_e[i];

    for (i = 0; i < 2; i++) pb_vars.costs += in_u_e[i] * in_u_e[i];

    std::cout << pb_vars.costs;

    return 0;
}
#endif
/*
 *			Cost function cal
 */
int cost_function_k_0_N() {
    int j, i, m;

    /*
     *            	Cost function construct:
     *
     * 		J(n)	=	h(x(N))	 +	l(x(k),u(k))
     * 		s.t		x(n+1)	=	f(x(k),u(k))
     *
     * 		J(n)=	1/2 * dx(N) * Q_N * dx(N)	+   // terminal cost
     * 				1/2 * dx(k) * Q_k * dx(k)   +   // intermediate cost
     * 				1/2 * du(k) * R_k * du(k)       // intermediate cost
     */
    for (j = 0; j < 8; j++) {
        pv_vars.dx[j] = pb_vars.x_des[j] - pb_vars.x0[j];
    }

    /*
     *                       TERMINAL COST
     *  Calculate dx[N] = = x[N] - x_des[N]
     *              k	=	0
     */
    for (j = 0; j < 8; j++) {
        pv_vars.dx_N[j] = pb_vars.x_des[j] - pb_vars.x0[j];

        pv_vars.dx_N[j] *= pb_vars.Q_N[i];
    }
    /*
     *  Calculate dx[k] = = x[k] - x_des[k]
     *              k	=	1:20
     */
    for (i = 1; i < 20; i++) {
        for (j = 0; j < 8; j++) {
            pv_vars.dx[i * 8 + j] = pb_vars.x_des[j] - pb_vars.x[i * 8 + j];
        }
    }

    /*              Sensitivity of the cost to go
     *      DJ(n)=  DXN(N)* Q_N +                   // terminal cost
     *              DXK(k)* Q_k +                   // intermediate cost
     *              DUK(k)* R_k                     // intermediate cost
     *
     */

    /*
     *                      TERMINAL COST
     *  Calculate   DXN(N)* Q_N
     *              k	=	19
     *              size: 8*1 = 8
     */
    for (i = 0; i < 8; i++) {
        /* code */
        pv_vars.DXN[i] = (pb_vars.x_des[i] - pb_vars.x[i]) * pb_vars.Q_N[i];
    }
    /*
     *                      INTERMEDIATE COST X
     *  Calculate  DXK(k)* Q_k = ( x(k) - x_des(k) ) * Q_k
     *             k	=	0:19
     *             size: 8*20 = 160
     */
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 8; j++) {
            pv_vars.DXK[i * 8 + j] = (pb_vars.x[i * 8 + j] - pb_vars.x_des[j]) * pb_vars.Q_k[j];
        }
    }
#if PRINT_D

    printf("\nDXK:\n[\n");
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 8; ++j) printf("\t%e", pv_vars.DXK[i * 8 + j]);
        printf("\n");
    }
    printf("]\n\n");
#endif
    /*
     *                      INTERMEDIATE COST U
     *  Calculate  DUK(k)* R_k = ( u(k) ) * R_k
     *             k	=	0:19
     *             size: 8*2 = 40
     */
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++) {
            pv_vars.DUK[i * 2 + j] = pb_vars.u[i * 2 + j] * pb_vars.R_k[j];
        }
    }
#if PRINT_D
    printf("\nDUK:\n[\n");
    for (i = 0; i < 20 + 1; ++i) {
        for (j = 0; j < 2; ++j) printf("\t%e", pv_vars.DUK[i * 2 + j]);
        printf("\n");
    }
    printf("]\n\n");
#endif

    /*
     *                      INTERMEDIATE COST X_U
     *  Calculate  DXUK(k)* [Q_k R_k]= [DXK(k) DUK(k)] T
     *             k	=	0:19
     *             size: (8+2)*20 = 200
     */
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 8; j++) {
            pv_vars.DXUK[i * 20 + j] = pv_vars.DXK[i * 8 + j];
        }
        for (j = 0; j < 2; j++) {
            pv_vars.DXUK[i * 20 + 8 + j] = pv_vars.DUK[i * 2 + j];
        }
    }
#if !PRINT_D

    printf("\nDXUK: \n[\n");
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 10; ++j) printf("\t%e", pv_vars.DXUK[i * 20 + j]);
        printf("\n");
    }
    printf("]\n\n");
#endif
    real_t Jz[20];

#if !CHECK_COST_FUNCTION

    for (i = 0; i < 20; i++) Jz[i] = 0;
#endif

        /*
         *               Calculate the norm L_2 of costfunction:
         *               J = 	0.5	* dx^2	+	0.5 * du^2
         */

#if !CHECK_COST_FUNCTION
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 8; j++) Jz[i] += std::pow(pv_vars.dx[i * 8 + j], 2);

        for (j = 0; j < 2; j++) Jz[i] += std::pow(pb_vars.u[i * 2 + j], 2);

        if (PRINT_COST) {
            std::cout << "J[" << i + 1 << "] = " << Jz[i] << "\n";
        }
    }
#endif
/*
 *              Print the cost function
 */
#if PRINT_COST
    std::cout << "Cost function"
              << "\n";
    std::cout << "[" << std::endl;
    std::cout << "]" << std::endl;
#endif
    // std::cout
    // store value
    for (i = 0; i < 20; i++) pv_vars.lsq_20[i] = 0.5 * Jz[i];

    return 0;
}
