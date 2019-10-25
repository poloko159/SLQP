#include "Header.h"

int multi_AB(real_t* A, real_t* B, real_t* out) {
        /*
        A: 8x8
        B: 8x2
        Out : 8x2
        */
        int i, j, k;

        for (i = 0; i < 16; i++) out[i] = 0;
        for (i = 0; i < 8; i++)  // 8 rows of out
        {
                for (j = 0; j < 2; j++)  // 2 column of out
                {
                        for (k = 0; k < 8; k++)  // 8 multipler of A*B
                        {
                                out[i * 2 + j] += A[i * 8 + k] * B[k * 2 + j];
                        }
                }
        }
        if (PRINT_MULTI_AB) {
                printf("\nA*B matrix:\n[\n");
                for (i = 0; i < 8; i++) {
                        std::cout << std::setprecision(10) << out[i * 2] << " " << out[i * 2 + 1] << std::endl;
                }
                printf("]\n\n");
        }
        return 0;
}
int multi_A_g(real_t* A, real_t* g, real_t* out) {
        /*
        A: 8x8
        g:	8x1
        Out : 8x1
        */
        int i, j, k;
        for (i = 0; i < 8; i++) out[i] = 0;
        for (i = 0; i < 8; i++)  // 8 rows of out
        {
                for (j = 0; j < 1; j++)  // 1 column of out
                {
                        for (k = 0; k < 8; k++)  // 8 multipler of A*g
                        {
                                out[i * 2 + j] += A[i * 8 + k] * g[k * 1 + j];
                        }
                }
        }
        return 0;
}

int multi_A_x(real_t* A, real_t* x, real_t* out) {
        /*
        A: 8x8
        x:	8x1
        Out : 8x1
        */
        int i, j, k;
        for (i = 0; i < 8; i++) out[i] = 0;
        for (i = 0; i < 8; i++)  // 8 rows of out
        {
                for (j = 0; j < 1; j++)  // 1 column of out
                {
                        for (k = 0; k < 8; k++)  // 8 multipler of A*g
                        {
                                out[i * 2 + j] += A[i * 8 + k] * x[k * 1 + j];
                        }
                }
        }
        return 0;
}

int multi_A_G(real_t* A, real_t* G, real_t* out) {
        /*
        A: 8x8
        G:	8x2
        Out : 8x1
        */
        int i, j, k;
        for (i = 0; i < 8; i++) out[i] = 0;
        for (i = 0; i < 8; i++)  // 8 rows of out
        {
                for (j = 0; j < 2; j++)  // 1 column of out
                {
                        for (k = 0; k < 8; k++)  // 8 multipler of A*g
                        {
                                out[i * 2 + j] += A[i * 8 + k] * G[k * 2 + j];
                        }
                }
        }
        return 0;
}
#if CONDENSING_USE
int transpose_matrix_G() {
        int rows, cols, k;
        /*
         *	Transpose G matrix
         *	G: 160*40
         *	GT:40*160
         *	Note: line: 0,41,82,...
         */

        /*	Get the first row of G -> GT*/

        for (rows = 0; rows < 40; rows++)  // 40 rows of GT
        {
                for (cols = 0; cols < 160; cols++)  // 160 cols of GT
                {
                        pv_vars.GT_con[rows * 40 + cols] = pv_vars.G_con[cols * 40 + rows];  // rows of GT_con = cols of G_con
                }
        }
        return 0;
}
#endif
int multi_GT_Q_g(real_t* GT_con, real_t* Q_con, real_t* g_con, real_t* h_con) {
        int i, j, k;
        /*	For block condensing h
         *	Gt_con: 40*160
         *	Q:		160*160
         *	g:		160*1
         *	h:		(40*160)*(160*160)*(160*1) = 40*1
         */

        /*	GT_Q first:
         *	Gt_con: 40*160
         *	Q:		160*160
         *	return to GT:
         */
        for (i = 0; i < 40; i++) h_con[i] = 0;

        for (i = 0; i < 40; i++)  // 40 rows of GT_con
        {
                GT_con[i * 161] *= Q_con[i];  // Q is Diagonal matrix so, just multi line:
        }

        /*	GT_Q_g :
         *	Gt_con: 40*160
         *	g:		160*1
         *	h:		40*160*160*160*160*1 = 40*1
         */
        for (i = 0; i < 40; i++)  // 40 rows of h
        {
                for (j = 0; j < 1; j++)  // 01 cols of h
                {
                        for (k = 0; k < 160; k++)  // 160 multiplers of GT_con*g_con
                        {
                                h_con[i * 40 + j] += GT_con[i * 40 + k] * g_con[k * 1 + j];
                        }
                }
        }

        return 0;
}

int multi_GT_Q_G_plus_R(real_t* R, real_t* GT_con, real_t* G_con, real_t* out) {
        int i, j, k;
        /* pre-requirement:
         *	known		R	:	40*40
         *	known		G	:	160*40
         *	known		Q	:	40*40
         *	known		GT	:	40*160
         *	Reset		out	:	40*40
         *	H:=	R+GT*Q*G	:	(40*40)+(40*160)*(40*40)*(160*40)
         *= 40*40 after calculating h: GT:= GT*Q H:=	R+GT*G		:
         *(40*40)+(40*160)*(160*40)			=	40*40
         */
        for (i = 0; i < 1600; i++) {
                out[i] = 0;
        }
        /*	GT_G first:
         *	Gt_con: (40*160)
         *	G:		(160*40)
         *	return to out:
         */
        for (i = 0; i < 40; i++)  // 40 rows of out
        {
                for (j = 0; j < 40; j++)  // 40 rows of out
                {
                        for (k = 0; k < 160; k++)  // 160 mul of out
                        {
                                out[i * 40 + j] += GT_con[i * 40 + k] * G_con[k * 40 + j];
                        }
                }
        }

        /*	done out<-R+out:
         *	out:		(40*40)
         *	R:			(40*40)
         *	return to out:
         */
        for (i = 0; i < 40; i++)
                for (j = 0; j < 40; j++) out[i * 40 + j] += R[i * 40 + j];

        return 0;
}