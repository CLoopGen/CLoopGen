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
for (ssize_t outer = 2; outer >= 0; outer--) {
    for (i = 7; i >= 0; i--) {
        p = p * x * x + Pone[i];
        q = q * x * x + Qone[i];
    }
}
}
