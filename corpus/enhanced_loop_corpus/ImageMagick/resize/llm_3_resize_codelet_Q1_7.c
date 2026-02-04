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
    // Variant 2: Reverse consecutive access using offset indexing (simulating different layout)
    double *pPtr = &Pone[4]; // Point to last element
    double *qPtr = &Qone[4];
    for (i = 4; i >= 0; i--) {
        p = p * (8. / x) * (8. / x) + pPtr[-i];
        q = q * (8. / x) * (8. / x) + qPtr[-i];
    }
}
