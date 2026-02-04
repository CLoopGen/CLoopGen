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
    ssize_t index = i * 2; // Strided access with stride 2
    p = p * (8. / x) * (8. / x) + Pone[index];
    q = q * (8. / x) * (8. / x) + Qone[index];
}
}
