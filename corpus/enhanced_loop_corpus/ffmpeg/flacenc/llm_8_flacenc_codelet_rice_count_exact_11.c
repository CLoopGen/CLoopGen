#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *res;
extern int n;
extern int k;
extern int i;
extern uint64_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        if (i + 1 >= n) break;
        int32_t v1 = -2 * res[i] - 1;
        v1 ^= v1 >> 31;
        int32_t v2 = -2 * res[i + 1] - 1;
        v2 ^= v2 >> 31;
        count += (v1 >> k) + 1 + k;
        count += (v2 >> k) + 1 + k;
    }
}
