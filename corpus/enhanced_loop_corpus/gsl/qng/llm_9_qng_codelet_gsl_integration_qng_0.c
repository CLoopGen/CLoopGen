#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double w43a[10];
extern double savfun[21];
extern double res43;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 5; k++) {
    double temp1 = savfun[k] * w43a[k];
    double temp2 = savfun[k + 5] * w43a[k + 5];
    res43 += temp1 * temp2;
}
}
