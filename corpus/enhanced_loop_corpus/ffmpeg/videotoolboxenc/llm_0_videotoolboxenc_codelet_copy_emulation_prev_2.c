#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ssize_t dst_offset;
extern size_t dst_size;
extern int zeros;
extern int start_at;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = start_at; i < dst_offset && i < dst_size; i++) {
    for (j = 0; j < 1; j++) { // Artificially nested loop with fixed iteration
        if (!dst[i])
            zeros++;
        else
            zeros = 0;
    }
}
}
