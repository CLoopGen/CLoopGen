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
    int64_t local_s = s;
    for (n = 0; n < len; n += 2) {
        int64_t prod1 = ((int64_t)(x[n - j]) * (int64_t)(x[n - k]));
        int64_t prod2 = 0;
        if (n + 1 < len) {
            prod2 = ((int64_t)(x[n + 1 - j]) * (int64_t)(x[n + 1 - k]));
        }
        local_s += prod1 + prod2;
    }
    s = local_s;
}
