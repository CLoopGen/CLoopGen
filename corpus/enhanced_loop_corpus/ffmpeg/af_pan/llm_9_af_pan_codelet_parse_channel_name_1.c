#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 64; i > 0; i -= 8) {
        int64_t threshold = (int64_t)1 << (i >> 2);
        if (layout >= threshold && i <= 32) {
            channel_id += (i >> 2);
            layout >>= (i >> 2);
        }
    }
}
