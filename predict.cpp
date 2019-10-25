#include "Header.h"
using namespace std;
int next_20_xk(real_t *x0, real_t *u, real_t *out_x) {
    /* Format:
     *	x0[8]
     *  u[20*2]
     *	out_x[8+8*20]->[168]
     */
    double x1_inter[8];
    double x0_inter[8];

    int i;  // the order of row
    int j;  // the order of column
    double u0[2];

    for (j = 0; j < 8; ++j) x0_inter[j] = x0[j];

    // store first row of out_x = x0
    for (j = 0; j < 8; ++j) out_x[j] = x0[j];

    // loop 20, start at row 1 of out_x0
    for (i = 0; i < 20; i++) {
        // store the value out_x(row i) of out_x to imtermediate
        // x0_inter
        for (j = 0; j < 8; ++j) {
            x0_inter[j] = out_x[j + i * 8];
        }
        // store the value u( row i)
        for (j = 0; j < 2; ++j) {
            u0[j] = u[j + i * 2];
        }
        // calculate x(k+1)->xi_inte
        maple_exp(x0_inter, u0, x1_inter);
        // store the xi_inter to out_x(row i+1)
        for (j = 0; j < 8; ++j) {
            out_x[j + (i + 1) * 8] = x1_inter[j];
        }
    }
#if PRIN_PREDICT
    printf("\nDifferential variables:\n[\n");
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 8; ++j) printf("\t%e", pb_vars.x[i * 8 + j]);
        printf("\n");
    }
    printf("]\n\n");
#endif
    return 0;
}
