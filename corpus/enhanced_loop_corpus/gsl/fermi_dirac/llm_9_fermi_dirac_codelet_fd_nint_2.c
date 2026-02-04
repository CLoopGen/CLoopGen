#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qcoeff[101];
extern double a;
extern double f;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp1, temp2;
for (i = 2; i <= n; i++) {
    temp1 = f * a;
    temp2 = temp1 + qcoeff[i];
    f = temp2;
}
}
