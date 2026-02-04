#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t order;
extern size_t i;
extern  double beta;
extern double q[11];
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= order * 2; ++k) {
    double qm1 = q[0];
    q[0] = q[1];
    for (i = 1; i <= (k % (order + 1)) + 1; ++i) {
        if (i < 10) {
            double tmp = q[i];
            q[i] = (i + 1.) * q[i + 1] + 2. * beta * qm1;
            qm1 = tmp;
        }
    }
}
}
