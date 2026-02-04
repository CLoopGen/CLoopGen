#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double p;
extern double q;
extern ssize_t i;
extern  double Pone[];
extern  double Qone[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with negative stride
    for (i = 8; i >= 0; i -= 2) {
        ssize_t idx = i / 2;
        p = p * (8. / x) * (8. / x) + Pone[idx];
        q = q * (8. / x) * (8. / x) + Qone[idx];
    }
}
