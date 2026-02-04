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
    for (i = 0; i < count; i += 2) {
        j = dest_index + i;
        dest[j] = dest[src_pos + i];
        if (i + 1 < count) {
            dest[j + 1] = dest[src_pos + i + 1];
        }
    }
}
