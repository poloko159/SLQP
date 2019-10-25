#include "Header.h"
#if CONDENSING_USE

// calculate of g condensing
int condensing_g_cal() {
    /* pre-requirement:
     *	known		pv_vars.A_20
     *	Reset		pv_vars.g_con
     */
    int i, j, k;
    // gg_con[0]<- x0
    for (i = 0; i < 160; i++) pv_vars.g_con[i] = 0;

    for (i = 0; i < 8; i++) pv_vars.g_con[i] = pb_vars.x0[i];

    // 20 times
    for (i = 0; i < 20 - 1; i++)
        multi_A_g(&(pv_vars.A_20[i * 64]),
                  &(pv_vars.g_con[i * 8]),  //
                  &(pv_vars.g_con[(i + 1) * 8]));

    return 0;
}

int condensing_G_cal() {
    /* pre-requirement:
     *	known		pv_vars.B_20
     *	known		pv_vars.A_20
     *	Reset		pv_vars.G_con
     */

    int i, j, k;
    for (i = 0; i < 3200; i++)  //	Reset		pv_vars.G_con
        pv_vars.G_con[i] = 0;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 2; j++) pv_vars.G_con[i * 2 + j] = pv_vars.B_20[i * 2 + j];
    for (i = 0; i < 20 - 1; i++) multi_A_G(&(pv_vars.A_20[i * 64]), &(pv_vars.G_con[i * 16]), &(pv_vars.G_con[(i + 1) * 16]));

    return 0;
}

int condensing_h_cal() {
    int i, j, k;
    /*
     *	Cal h = GT_con*Q*g_con
     */
    multi_GT_Q_g(pv_vars.GT_con, pb_vars.Q_con, pv_vars.g_con, pv_vars.h_con);
    return 0;
}

int condensing_H_cal() {
    int i, j, k;
    /* pre-requirement:
     *	known		R	:	40*40
     *	known		G	:	160*40
     *	known		Q	:	40*40
     *	known		GT	:	40*160
     *	H:=	R+GT*Q*G	:	(40*40)+(40*160)*(40*40)*(160*40)
     *= 40*40 after calculating h: GT:= GT*Q H:=	R+GT*G		:
     *(40*40)+(40*160)*(160*40)			=	40*40
     */
    multi_GT_Q_G_plus_R(pb_vars.R_con, pv_vars.GT_con, pv_vars.G_con, pv_vars.H_con);

    return 0;
}
#endif