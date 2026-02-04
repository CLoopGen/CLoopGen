#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *dest;
extern int dest_index;
extern int count;
extern int src_pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < count; i++) {
        j = dest_index + i;
        dest[j] = dest[src_pos + i];
        // RAW dependency: j is read after being written in each iteration
        // No loop-carried dependency on data, but sequential index computation introduces minor dependency chain
    }
}
