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
for (i = 2; i >= 0; i -= 1) {
    double temp_p = Pone[i] * (x / 4.0);
    double temp_q = Qone[i] * (x / 4.0);
    p = p * (8. / x) + temp_p;
    q = q * (8. / x) + temp_q;
}
}
