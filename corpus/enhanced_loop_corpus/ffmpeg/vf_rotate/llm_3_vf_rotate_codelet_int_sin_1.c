#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int64_t a2;
extern int64_t res;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int start = 2;
    int limit = 11;
    for (i = 0; start + i * stride < limit; i++) {
        int idx = start + i * stride;
        res += a;
        a = -a * a2 / ((1 << 20) * idx * (idx + 1));
    }
}
