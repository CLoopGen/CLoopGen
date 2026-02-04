#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t val, next_val;
    int local_dsize = dsize;
    for (i = 0; i < size; i++) {
        val = src[i];
        // Introduce artificial WAW and WAR dependencies via scheduled writes
        if (val == 3 && i >= 2 && src[i-1] == 0 && src[i-2] == 0 && i < size - 1) {
            next_val = src[i+1];
            if (next_val < 4) {
                dst[local_dsize] = next_val;
                local_dsize++;
                i++; // Simulate consuming two elements
            } else {
                dst[local_dsize] = val;
                local_dsize++;
            }
        } else {
            dst[local_dsize] = val;
            local_dsize++;
        }
    }
    dsize = local_dsize; // Resolve loop-carried output dependency at exit
}
