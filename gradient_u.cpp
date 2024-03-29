#include "Header.h"

int get_B_k(real_t *in_x, real_t *in_u, real_t *out)

{
        int i;
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
        for (i = 0; i < 16; i++) {
                out[i] = 0;
        }
        real_t G = 0.9986;
        real_t g = 9.8066;

        out[0] = 0.2604166666e-7 * G * ux * x2 + 0.1041666667e-5 * G * ux * x1 -
                 0.1302083333e-7 * x4 * G * G * g * sin(x3) +
                 0.2604166667e-6 * G * g * sin(x3) * cos(0.2500000000e-1 * x4) *
                     sin(0.6250000000e-3 * ux) +
                 0.2604166667e-6 * G * g * sin(x3) * sin(0.2500000000e-1 * x4) *
                     cos(0.6250000000e-3 * ux) +
                 0.2604166667e-6 * G * g * cos(x3) * sin(0.2500000000e-1 * x4) *
                     sin(0.6250000000e-3 * ux) -
                 0.2604166667e-6 * G * g * cos(x3) * cos(0.2500000000e-1 * x4) *
                     cos(0.6250000000e-3 * ux) +
                 0.1302083333e-7 * pow(x4, 0.3e1) * G * G * x1 +
                 0.3255208334e-9 * ux * G * G * x4 * x4 * x1 -
                 0.3255208334e-9 * ux * G * G * g * sin(x3) +
                 0.4166666668e-4 * G * x4 * x1 + 0.1041666667e-5 * G * x4 * x2;
        out[2] = -0.5208333334e-7 * ux * G * G * g * sin(x3) *
                     cos(0.2500000000e-1 * x4) -
                 0.5208333334e-7 * ux * G * G * g * cos(x3) *
                     sin(0.2500000000e-1 * x4) +
                 0.1041666667e-4 * G * g * cos(x3) * sin(0.5e-1 * x4) *
                     sin(0.1250000000e-2 * ux) -
                 0.1041666667e-4 * G * g * cos(x3) * cos(0.5e-1 * x4) *
                     cos(0.1250000000e-2 * ux) +
                 0.1041666667e-4 * G * g * sin(x3) * cos(0.5e-1 * x4) *
                     sin(0.1250000000e-2 * ux) +
                 0.1041666667e-4 * G * g * sin(x3) * sin(0.5e-1 * x4) *
                     cos(0.1250000000e-2 * ux) -
                 0.1041666667e-5 * x4 * G * G * g * sin(x3) *
                     cos(0.2500000000e-1 * x4) -
                 0.1041666667e-5 * x4 * G * G * g * cos(x3) *
                     sin(0.2500000000e-1 * x4) +
                 0.1041666667e-4 * G * g * sin(x3) * cos(0.2500000000e-1 * x4) *
                     sin(0.6250000000e-3 * ux) +
                 0.1041666667e-4 * G * g * sin(x3) * sin(0.2500000000e-1 * x4) *
                     cos(0.6250000000e-3 * ux) +
                 0.1041666667e-4 * G * g * cos(x3) * sin(0.2500000000e-1 * x4) *
                     sin(0.6250000000e-3 * ux) -
                 0.1041666667e-4 * G * g * cos(x3) * cos(0.2500000000e-1 * x4) *
                     cos(0.6250000000e-3 * ux) +
                 0.3906250000e-7 * pow(x4, 0.3e1) * G * G * x2 +
                 0.2083333333e-5 * pow(x4, 0.3e1) * G * G * x1 +
                 0.2500000000e-2 * G * x4 * x1 + 0.8333333334e-4 * G * x4 * x2 +
                 0.1627604167e-11 * pow(ux, 0.3e1) * G * G * x2 +
                 0.6510416668e-10 * pow(ux, 0.3e1) * G * G * x1 +
                 0.3125000000e-5 * G * ux * x2 + 0.8333333334e-4 * G * ux * x1 +
                 0.4231770834e-8 * ux * G * G * x4 * x4 * x2 +
                 0.5859375000e-8 * x4 * ux * ux * G * G * x1 +
                 0.1464843750e-9 * x4 * ux * ux * G * G * x2 -
                 0.5208333334e-6 * x4 * G * G * g * sin(x3) +
                 0.1822916667e-6 * ux * G * G * x4 * x4 * x1 -
                 0.1302083334e-7 * ux * G * G * g * sin(x3);
        out[4] = 0.1250000000e-2;
        out[6] = 0.5000000000e-1;

        out[9] = 0.2604166666e-7 * G * uy * x6 + 0.1041666667e-5 * G * uy * x5 -
                 0.1302083333e-7 * x8 * G * G * g * sin(x7) +
                 0.2604166667e-6 * G * g * sin(x7) * cos(0.2500000000e-1 * x8) *
                     sin(0.6250000000e-3 * uy) +
                 0.2604166667e-6 * G * g * sin(x7) * sin(0.2500000000e-1 * x8) *
                     cos(0.6250000000e-3 * uy) +
                 0.2604166667e-6 * G * g * cos(x7) * sin(0.2500000000e-1 * x8) *
                     sin(0.6250000000e-3 * uy) -
                 0.2604166667e-6 * G * g * cos(x7) * cos(0.2500000000e-1 * x8) *
                     cos(0.6250000000e-3 * uy) +
                 0.4166666668e-4 * G * x8 * x5 + 0.1041666667e-5 * G * x8 * x6 +
                 0.1302083333e-7 * pow(x8, 0.3e1) * G * G * x5 +
                 0.3255208334e-9 * uy * G * G * x8 * x8 * x5 -
                 0.3255208334e-9 * uy * G * G * g * sin(x7);
        out[11] =
            0.1041666667e-4 * G * g * sin(x7) * sin(0.2500000000e-1 * x8) *
                cos(0.6250000000e-3 * uy) +
            0.1041666667e-4 * G * g * cos(x7) * sin(0.2500000000e-1 * x8) *
                sin(0.6250000000e-3 * uy) -
            0.1041666667e-4 * G * g * cos(x7) * cos(0.2500000000e-1 * x8) *
                cos(0.6250000000e-3 * uy) -
            0.5208333334e-7 * uy * G * G * g * sin(x7) *
                cos(0.2500000000e-1 * x8) -
            0.5208333334e-7 * uy * G * G * g * cos(x7) *
                sin(0.2500000000e-1 * x8) +
            0.1041666667e-4 * G * g * sin(x7) * cos(0.5e-1 * x8) *
                sin(0.1250000000e-2 * uy) +
            0.1041666667e-4 * G * g * sin(x7) * sin(0.5e-1 * x8) *
                cos(0.1250000000e-2 * uy) +
            0.1041666667e-4 * G * g * cos(x7) * sin(0.5e-1 * x8) *
                sin(0.1250000000e-2 * uy) -
            0.1041666667e-4 * G * g * cos(x7) * cos(0.5e-1 * x8) *
                cos(0.1250000000e-2 * uy) -
            0.1041666667e-5 * x8 * G * G * g * sin(x7) *
                cos(0.2500000000e-1 * x8) -
            0.1041666667e-5 * x8 * G * G * g * cos(x7) *
                sin(0.2500000000e-1 * x8) +
            0.1041666667e-4 * G * g * sin(x7) * cos(0.2500000000e-1 * x8) *
                sin(0.6250000000e-3 * uy) +
            0.3125000000e-5 * G * uy * x6 + 0.8333333334e-4 * G * uy * x5 +
            0.2500000000e-2 * G * x8 * x5 + 0.8333333334e-4 * G * x8 * x6 +
            0.2083333333e-5 * pow(x8, 0.3e1) * G * G * x5 +
            0.6510416668e-10 * pow(uy, 0.3e1) * G * G * x5 +
            0.1627604167e-11 * pow(uy, 0.3e1) * G * G * x6 +
            0.1822916667e-6 * uy * G * G * x8 * x8 * x5 -
            0.1302083334e-7 * uy * G * G * g * sin(x7) +
            0.4231770834e-8 * uy * G * G * x8 * x8 * x6 +
            0.5859375000e-8 * x8 * uy * uy * G * G * x5 +
            0.1464843750e-9 * x8 * uy * uy * G * G * x6 -
            0.5208333334e-6 * x8 * G * G * g * sin(x7) +
            0.3906250000e-7 * pow(x8, 0.3e1) * G * G * x6;
        out[13] = 0.1250000000e-2;
        out[15] = 0.5000000000e-1;
        /*
        cout << "Bk" << endl;
        for (i = 0; i < 8; i++)
        {
                cout << out[i * 2] << " " << out[i * 2 + 1];
                cout << "\n";
        }
        */
        return 0;
}
/*
 *	Abadoned
 */
#if !ABANDONED_CODE
int finite_diff(real_t *in_x, real_t *in_u, real_t *out) {
        real_t s;

        return 0;
}
int gradient_u_lsq() {
        /*

        */
        return 0;
}
#endif