#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective loop iterations by changing control flow with an outer filter
int outer_step;
for (outer_step = 4; outer_step > 0; outer_step--) {
    int temp_i = 1 << outer_step;  // Limit i values to 16, 8, 4, 2
    if (layout >= 1LL << temp_i) {
        channel_id += temp_i;
        layout >>= temp_i;
    }
}
}
