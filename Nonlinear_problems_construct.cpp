#include "Header.h"
/*
    In this file, the nonlinear problem will be construct:
    minimize    f(u)
    s.t.        g(u) = 0;
                h(u) < h;

                x(k+1) = f(x(k),u(k));
                x(k) = x_k;

                Using SQP
 */
