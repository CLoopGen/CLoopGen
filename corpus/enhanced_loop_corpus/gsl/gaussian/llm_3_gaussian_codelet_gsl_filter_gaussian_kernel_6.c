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
size_t offset = 0;
for (k = 1; k <= order; ++k) {
    double qm1 = q[offset];
    q[offset] = q[offset + 1];
    for (i = 1; i <= k; ++i) {
        double tmp = q[offset + i];
        q[offset + i] = (i + 1.) * q[offset + i + 1] + 2. * beta * qm1;
        qm1 = tmp;
    }
    offset += 2;
}
}
