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
    for (i = 7; i >= 0; i--) {
        if (x > 0.0) {
            p = p * x * x + Pone[i];
            q = q * x * x + Qone[i];
        } else {
            p = Pone[i];
            q = Qone[i];
        }
    }
}
