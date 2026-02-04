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
    double local_p = p;
    double local_q = q;
    for (i = 4; i >= 0; i--) {
        double factor = (8. / x) * (8. / x);
        local_p = local_p * factor + Pone[i];
        local_q = local_q * factor + Qone[i];
    }
    p = local_p;
    q = local_q;
}
