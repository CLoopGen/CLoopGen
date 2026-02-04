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
    double prev_Ma0n = Ma0n;
    double prev_Ma0np1 = Ma0np1;
    double new_Ma0nm1;
    for (n = a0 - 1; n > b; n--) {
        new_Ma0nm1 = (-n * (1 - n - x) * prev_Ma0n - x * (n - a0) * prev_Ma0np1) / (n * (n - 1.));
        prev_Ma0np1 = prev_Ma0n;
        prev_Ma0n = new_Ma0nm1;
    }
    Ma0nm1 = new_Ma0nm1;
    Ma0n = prev_Ma0n;
    Ma0np1 = prev_Ma0np1;
}
