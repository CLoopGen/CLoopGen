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
    for (i = 0; i < count; i++) {
        if ((dest_index + i) != (src_pos + i)) {
            dest[dest_index + i] = dest[src_pos + i];
        }
    }
}
