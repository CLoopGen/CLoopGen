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
    for (i = 4; i >= 0; i--) {
        if (p > q) {
            p = p * (8. / x) * (8. / x) + Pone[i];
        } else {
            q = q * (8. / x) * (8. / x) + Qone[i];
        }
    }
}
