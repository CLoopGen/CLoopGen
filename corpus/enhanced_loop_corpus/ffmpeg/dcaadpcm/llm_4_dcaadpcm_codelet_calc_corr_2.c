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
    if (len <= 0) return;
    for (n = 0; n < len; n++) {
        int32_t val1 = x[n - j];
        int32_t val2 = x[n - k];
        s += (int64_t)val1 * val2;
    }
}
