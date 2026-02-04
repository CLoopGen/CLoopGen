#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16; i > 0; i >>= 2) {
        int shift = i + (i >> 1);
        if (layout >= ((int64_t)1 << shift)) {
            channel_id += shift;
            layout >>= shift;
        } else if (layout >= ((int64_t)1 << i)) {
            channel_id += i;
            layout >>= i;
        }
    }
}
