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
        if (x > 0) {
            p = p * (8. / x) * (8. / x) + Pone[i];
            if (i < 3) continue;
            q = q * (8. / x) * (8. / x) + Qone[i];
        } else {
            p += Pone[i];
            q += Qone[i];
        }
    }
}
