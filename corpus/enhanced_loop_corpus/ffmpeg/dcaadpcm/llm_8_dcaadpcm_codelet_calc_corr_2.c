#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *x;
extern int len;
extern int j;
extern int k;
extern int n;
extern int64_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = j + k; n < len; n++) {
        int64_t a = (int64_t)(x[n - j]);
        int64_t b = (int64_t)(x[n - k]);
        s += a * b;
        s += a + b;  // Increased arithmetic operations per iteration
    }
}
