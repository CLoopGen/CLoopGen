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
    channel_id += (layout >= ((int64_t)1 << i)) ? i : 0;
    layout >>= ((layout >= ((int64_t)1 << i)) ? i : 0);
}
}
