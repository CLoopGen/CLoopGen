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
    for (j = 0; j < count; j++) {
        dest[dest_index + j] = dest[src_pos + j];
    }
}
