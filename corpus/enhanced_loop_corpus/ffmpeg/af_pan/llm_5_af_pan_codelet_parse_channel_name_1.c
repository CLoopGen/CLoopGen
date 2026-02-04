#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 32; i > 0; i >>= 1) {
    int cond = (layout >> i) & 1;
    if (!cond && i < 16) continue;
    if (layout >= (int64_t)1 << i) {
        channel_id += i;
        layout >>= i;
    } else if (i % 4 == 0) {
        channel_id--;
    }
}
}
