#include "Header.h"

priv pv_vars;
pub pb_vars;

int main() {
    int i, j, k, l, m, n;

    /* SOLVER SQP FULL STEP*/
    // INIT:
    pb_vars.x15 = 1.0;
    pb_vars.x26 = 1.0;
    pb_vars.x37 = 1.0;
    pb_vars.x48 = 1.0;
    pb_vars.u12 = 1.0;

    if (1) {
        for (i = 0; i < 8; i++) pb_vars.x0[i] = 0;

        pb_vars.x0[0] = 0.01;
        pb_vars.x0[1] = -0.01;

        for (i = 0; i < 40; i++) pb_vars.u[i] = 0;

        for (i = 0; i < 8; i++) pb_vars.x_des[i] = 0;

        for (i = 0; i < 2; i++) pb_vars.u0[i] = 0;

        init_QN_QK_RK();
        next_20_xk(pb_vars.x0, pb_vars.u, pb_vars.x);

        cost_function_k_0_N();
    }
    inverse_kinematics(10 * PI / 180, 0);
    return 0;
}
