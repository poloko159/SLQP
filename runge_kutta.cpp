#include "Header.h"

void model_function(const real_t* in_x, const real_t* in_u, real_t* out) // x1 -> x8, u1, u2
{
        real_t h = 0.05;
        real_t g = 9.8066;
        real_t G = 0.9908;

        out[0] = h * in_x[0];
        out[1] = h * G * (in_x[0] * in_x[3] * in_x[3] + in_x[2] * in_x[4] * in_x[6] - g * sin(in_x[2]));
        out[2] = h * in_x[3];
        out[3] = h * in_u[0];

        out[4] = h * in_x[5];
        out[5] = h * G * (in_x[4] * in_x[7] * in_x[7] + in_x[0] * in_x[4] * in_x[6] - g * sin(in_x[6]));
        out[6] = h * in_x[7];
        out[7] = h * in_u[1];
};

int maple_exp(real_t* in_x, real_t* in_u, real_t* out)
{

        real_t h = 0.05;
        real_t g = 9.8066;
        real_t G = 0.9908;

        real_t x1 = in_x[0];
        real_t x2 = in_x[1];
        real_t x3 = in_x[2];
        real_t x4 = in_x[3];
        real_t x5 = in_x[4];
        real_t x6 = in_x[5];
        real_t x7 = in_x[6];
        real_t x8 = in_x[7];

        real_t ux = in_u[0];
        real_t uy = in_u[1];

        out[0] = x1 + h * x2 / 0.6E1 + h * (x2 + h * G * (x4 * x4 * x1 + x5 * x4 * x8 - g * sin(x3)) / 0.2E1) / 0.3E1 + h * (x2 + h * G * (pow(x4 + h * ux / 0.2E1, 0.2E1) * (x1 + h * x2 / 0.2E1) + (x5 + h * x6 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x3 + h * x4 / 0.2E1)) / 0.2E1) / 0.3E1 + h * (x2 + h * G * (pow(x4 + h * ux / 0.2E1, 0.2E1) * (x1 + h * (x2 + h * G * (x4 * x4 * x1 + x5 * x4 * x8 - g * sin(x3)) / 0.2E1) / 0.2E1) + (x5 + h * (x6 + h * G * (x1 * x4 * x8 + x8 * x8 * x5 - g * sin(x7)) / 0.2E1) / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x3 + h * (x4 + h * ux / 0.2E1) / 0.2E1))) / 0.6E1;
        out[1] = x2 + h * G * (x4 * x4 * x1 + x5 * x4 * x8 - g * sin(x3)) / 0.6E1 + h * G * (pow(x4 + h * ux / 0.2E1, 0.2E1) * (x1 + h * x2 / 0.2E1) + (x5 + h * x6 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x3 + h * x4 / 0.2E1)) / 0.3E1 + h * G * (pow(x4 + h * ux / 0.2E1, 0.2E1) * (x1 + h * (x2 + h * G * (x4 * x4 * x1 + x5 * x4 * x8 - g * sin(x3)) / 0.2E1) / 0.2E1) + (x5 + h * (x6 + h * G * (x1 * x4 * x8 + x8 * x8 * x5 - g * sin(x7)) / 0.2E1) / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x3 + h * (x4 + h * ux / 0.2E1) / 0.2E1)) / 0.3E1 + h * G * (pow(h * ux + x4, 0.2E1) * (x1 + h * (x2 + h * G * (pow(x4 + h * ux / 0.2E1, 0.2E1) * (x1 + h * x2 / 0.2E1) + (x5 + h * x6 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x3 + h * x4 / 0.2E1)) / 0.2E1)) + (x5 + h * (x6 + h * G * (pow(x8 + h * uy / 0.2E1, 0.2E1) * (x5 + h * x6 / 0.2E1) + (x1 + h * x2 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x7 + h * x8 / 0.2E1)) / 0.2E1)) * (h * ux + x4) * (h * uy + x8) - g * sin(x3 + h * (x4 + h * ux / 0.2E1))) / 0.6E1;
        out[2] = x3 + h * x4 / 0.6E1 + 0.2E1 / 0.3E1 * h * (x4 + h * ux / 0.2E1) + h * (h * ux + x4) / 0.6E1;
        out[3] = h * ux + x4;
        out[4] = x5 + h * x6 / 0.6E1 + h * (x6 + h * G * (x1 * x4 * x8 + x8 * x8 * x5 - g * sin(x7)) / 0.2E1) / 0.3E1 + h * (x6 + h * G * (pow(x8 + h * uy / 0.2E1, 0.2E1) * (x5 + h * x6 / 0.2E1) + (x1 + h * x2 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x7 + h * x8 / 0.2E1)) / 0.2E1) / 0.3E1 + h * (x6 + h * G * (pow(x8 + h * uy / 0.2E1, 0.2E1) * (x5 + h * (x6 + h * G * (x1 * x4 * x8 + x8 * x8 * x5 - g * sin(x7)) / 0.2E1) / 0.2E1) + (x1 + h * (x2 + h * G * (x4 * x4 * x1 + x5 * x4 * x8 - g * sin(x3)) / 0.2E1) / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x7 + h * (x8 + h * uy / 0.2E1) / 0.2E1))) / 0.6E1;
        out[5] = x6 + h * G * (x1 * x4 * x8 + x8 * x8 * x5 - g * sin(x7)) / 0.6E1 + h * G * (pow(x8 + h * uy / 0.2E1, 0.2E1) * (x5 + h * x6 / 0.2E1) + (x1 + h * x2 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x7 + h * x8 / 0.2E1)) / 0.3E1 + h * G * (pow(x8 + h * uy / 0.2E1, 0.2E1) * (x5 + h * (x6 + h * G * (x1 * x4 * x8 + x8 * x8 * x5 - g * sin(x7)) / 0.2E1) / 0.2E1) + (x1 + h * (x2 + h * G * (x4 * x4 * x1 + x5 * x4 * x8 - g * sin(x3)) / 0.2E1) / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x7 + h * (x8 + h * uy / 0.2E1) / 0.2E1)) / 0.3E1 + h * G * (pow(h * uy + x8, 0.2E1) * (x5 + h * (x6 + h * G * (pow(x8 + h * uy / 0.2E1, 0.2E1) * (x5 + h * x6 / 0.2E1) + (x1 + h * x2 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x7 + h * x8 / 0.2E1)) / 0.2E1)) + (x1 + h * (x2 + h * G * (pow(x4 + h * ux / 0.2E1, 0.2E1) * (x1 + h * x2 / 0.2E1) + (x5 + h * x6 / 0.2E1) * (x4 + h * ux / 0.2E1) * (x8 + h * uy / 0.2E1) - g * sin(x3 + h * x4 / 0.2E1)) / 0.2E1)) * (h * ux + x4) * (h * uy + x8) - g * sin(x7 + h * (x8 + h * uy / 0.2E1))) / 0.6E1;
        out[6] = x7 + h * x8 / 0.6E1 + 0.2E1 / 0.3E1 * h * (x8 + h * uy / 0.2E1) + h * (h * uy + x8) / 0.6E1;
        out[7] = h * uy + x8;

        return 0;
}

void rugenkutta_classic()
{
        int i;
        real_t h = 0.05;
        real_t g = 9.8066;
        real_t G = 0.9908;

        /* loop 1
	*	k1_inter = x0
	*	k1:=h*f(k1_inter)
	*/

        //	k1_inter = x0
        for (i = 0; i <= 8; ++i) {
                pv_vars.runge_kutta_k1_inter[i] = pb_vars.x0[i];
        }
        //	k1:=h*f(k1_inter)
        model_function(pv_vars.runge_kutta_k1_inter, pb_vars.u0, pv_vars.runge_kutta_k1);

        /* loop 2
	*	k2_inter = X+k1/2
	*	k2:=h*f(k2_inter)
	*/

        //	k2_inter = X + k1 / 2
        for (i = 0; i <= 8; ++i) {
                pv_vars.runge_kutta_k2_inter[i] = pb_vars.x0[i] + pv_vars.runge_kutta_k1[i] / 2;
        }
        //	k2:=h*f(k2_inter)
        model_function(pv_vars.runge_kutta_k2_inter, pb_vars.u0, pv_vars.runge_kutta_k2);

        /* loop 3
	*	k3_inter:=X + k2 / 2
	*	k3 = h* f(k3_inter)
	*/

        //	k3_inter = X + k2 / 2
        for (i = 0; i <= 8; ++i) {
                pv_vars.runge_kutta_k3_inter[i] = pb_vars.x0[i] + pv_vars.runge_kutta_k2[i] / 2;
        }
        //	k3 = h* f(k3_inter)
        model_function(pv_vars.runge_kutta_k3_inter, pb_vars.u0, pv_vars.runge_kutta_k3);

        /* loop 4
	*	k4_inter:=X + k3 / 2
	*	k4 = h* f(k4_inter)
	*/
        for (i = 0; i <= 8; ++i) {
                pv_vars.runge_kutta_k4_inter[i] = pb_vars.x0[i] + pv_vars.runge_kutta_k3[i];
        }
        model_function(pv_vars.runge_kutta_k4_inter, pb_vars.u0, pv_vars.runge_kutta_k4);
        /* loop fin
	*	x(k+1)=x(k) + 1/6(k1+2*k2+2*k3+k4)
	*/
}
