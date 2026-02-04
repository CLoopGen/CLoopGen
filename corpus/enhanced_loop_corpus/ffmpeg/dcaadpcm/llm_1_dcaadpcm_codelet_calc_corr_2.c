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
    for (int outer = 0; outer < 1; outer++) {
        for (n = 0; n < len; n++) {
            s += ((int64_t)(x[n - j]) * (int64_t)(x[n - k]));
        }
    }
}
