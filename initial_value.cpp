/*
 * 	matrix W (and Wn).
 *
 * 	constrains for u accroding to x: -0.17
 * 	<=[roll;pitch]<=0.17 run first
 */

#include "Header.h"

void init_weight_matrix_W_and_Wn() {
    int i;
/*
 *		intermediate cost
 */
#if CONDENSING_USE

    for (i = 0; i < 10; ++i) pb_vars.W[i * 11] = 1;

    /* 	[0][0] = 	200 x_0		x */
    pb_vars.W[0] = 200;

    /* 	[5][5]	=	200	x_4		y */
    pb_vars.W[44] = 200;

    /*
     *		terminal cost
     */
    for (i = 0; i < 8; ++i) pb_vars.WN[i * 9] = 1;

    /* [0][0] = 	200 x_0		x */
    pb_vars.WN[0] = 500;

    /* 	[5][5]	=	200	x_4		y */
    pb_vars.WN[44] = 500;

    /*
     *		 cost
     */
    for (i = 0; i < 8; i++) {
        /* code */
        pb_vars.W[i] = 2;
        pb_vars.WN[i] = 5;
    }
    /*
     *		intermediate cost
     */

    /* [0][0] = 	200 x_0		x1 */
    pb_vars.W[0] = 20;
    /* [0][0] = 	200 x_0		x1_dot */
    pb_vars.W[1] = 20;

    /* [0][0] = 	200 x_0		x2 */
    pb_vars.W[3] = 20;
    /* [0][0] = 	200 x_0		x2_dot */
    pb_vars.W[4] = 20;

    /*
     *		terminal cost
     */
    /* [0][0] = 	200 x_0		x1 */
    pb_vars.WN[0] = 30;
    /* [0][0] = 	200 x_0		x1_dot */
    pb_vars.WN[1] = 30;

    /* [0][0] = 	200 x_0		x2 */
    pb_vars.WN[3] = 30;
    /* [0][0] = 	200 x_0		x2_dot */
    pb_vars.WN[4] = 30;
#endif
}

void init_QN_QK_RK() {
    pb_vars.Q_N[0] = pb_vars.x15;
    pb_vars.Q_N[1] = pb_vars.x26;
    pb_vars.Q_N[2] = pb_vars.x37;
    pb_vars.Q_N[3] = pb_vars.x48;
    pb_vars.Q_N[4] = pb_vars.x15;
    pb_vars.Q_N[5] = pb_vars.x26;
    pb_vars.Q_N[6] = pb_vars.x37;
    pb_vars.Q_N[7] = pb_vars.x48;

    pb_vars.Q_k[0] = pb_vars.x15;
    pb_vars.Q_k[1] = pb_vars.x26;
    pb_vars.Q_k[2] = pb_vars.x37;
    pb_vars.Q_k[3] = pb_vars.x48;
    pb_vars.Q_k[4] = pb_vars.x15;
    pb_vars.Q_k[5] = pb_vars.x26;
    pb_vars.Q_k[6] = pb_vars.x37;
    pb_vars.Q_k[7] = pb_vars.x48;

    pb_vars.R_k[0] = pb_vars.u12;
    pb_vars.R_k[1] = pb_vars.u12;

    pb_vars.Q_k_R_k[0] = pb_vars.x15;
    pb_vars.Q_k_R_k[1] = pb_vars.x26;
    pb_vars.Q_k_R_k[2] = pb_vars.x37;
    pb_vars.Q_k_R_k[3] = pb_vars.x48;
    pb_vars.Q_k_R_k[4] = pb_vars.x15;
    pb_vars.Q_k_R_k[5] = pb_vars.x26;
    pb_vars.Q_k_R_k[6] = pb_vars.x37;
    pb_vars.Q_k_R_k[7] = pb_vars.x48;

    pb_vars.Q_k_R_k[8] = pb_vars.u12;
    pb_vars.Q_k_R_k[9] = pb_vars.u12;
}
