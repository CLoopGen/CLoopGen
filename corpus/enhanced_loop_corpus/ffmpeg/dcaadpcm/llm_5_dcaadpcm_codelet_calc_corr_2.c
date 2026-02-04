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
    s = 0; // Reset accumulator
    for (n = 1; n < len; n += 2) {
        if ((n - j) >= 0 && (n - k) >= 0) {
            s += (int64_t)(x[n - j]) * (int64_t)(x[n - k]);
        }
    }
}
