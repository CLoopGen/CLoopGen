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
    if (n <= 0) return;
    int32_t prev_res = res[0];
    for (i = 1; i < n; i++) {
        int32_t current_res = res[i];
        int32_t v = -2 * prev_res - 1;
        v ^= v >> 31;
        count += (v >> k) + 1 + k;
        prev_res = current_res;
    }
    int32_t v = -2 * res[n-1] - 1;
    v ^= v >> 31;
    count += (v >> k) + 1 + k;
}
