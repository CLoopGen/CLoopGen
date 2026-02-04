#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with offset read pattern using auxiliary index
    int idx = 0;
    for (n = 1; n < 25; n++) {
        idx = n * 2;
        t[idx] = t[idx - 1] * (x / idx);
    }
}
