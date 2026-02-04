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
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < n; i++) {
            int32_t v = -2 * res[i] - 1;
            v ^= v >> 31;
            count += (v >> k) + 1 + k;
        }
    }
}
