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
        int shift = (layout >= (1LL << i));
        if (!shift && i == 16) continue;
        channel_id += shift ? i : 0;
        layout >>= shift ? i : 0;
    }
}
