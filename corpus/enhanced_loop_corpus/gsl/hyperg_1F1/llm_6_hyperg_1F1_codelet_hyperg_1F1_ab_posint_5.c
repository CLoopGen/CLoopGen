#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int b;
extern  double x;
extern int a0;
extern int n;
extern double Ma0np1;
extern double Ma0n;
extern double Ma0nm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_Ma0nm1, temp_Ma0n, temp_Ma0np1;
    temp_Ma0n = Ma0n;
    temp_Ma0np1 = Ma0np1;
    for (n = a0 - 1; n > b; n--) {
        temp_Ma0nm1 = (-n * (1 - n - x) * temp_Ma0n - x * (n - a0) * temp_Ma0np1) / (n * (n - 1.));
        temp_Ma0np1 = temp_Ma0n;
        temp_Ma0n = temp_Ma0nm1;
    }
    Ma0nm1 = temp_Ma0nm1;
    Ma0n = temp_Ma0n;
    Ma0np1 = temp_Ma0np1;
}
