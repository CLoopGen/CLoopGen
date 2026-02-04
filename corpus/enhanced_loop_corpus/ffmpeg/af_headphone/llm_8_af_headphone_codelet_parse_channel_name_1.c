#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 32; i > 0; i >>= 2) {
        if (layout >= 1LL << i) {
            channel_id += i;
            layout >>= i;
        }
        if (layout >= 1LL << (i >> 1)) {
            channel_id += i >> 1;
            layout >>= i >> 1;
        }
    }
}
