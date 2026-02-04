#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16; i > 0; i >>= 2) { // Reduced trip count by starting lower and shifting more aggressively
        if (layout >= (1LL << i)) {
            channel_id += i;
            layout >>= i;
        }
        // Unroll effect simulated with multiple checks in one iteration
        if (i > 4 && layout >= (1LL << (i >> 1))) {
            channel_id += (i >> 1);
            layout >>= (i >> 1);
        }
    }
}
