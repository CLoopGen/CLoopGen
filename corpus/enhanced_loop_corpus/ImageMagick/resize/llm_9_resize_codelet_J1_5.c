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
for (i = 3; i >= 0; i--) {
    double temp1 = Pone[i*2] + Pone[i*2+1] * x;
    double temp2 = Qone[i*2] + Qone[i*2+1] * x;
    p = p * x * x * x * x + temp1;
    q = q * x * x * x * x + temp2;
}
}
