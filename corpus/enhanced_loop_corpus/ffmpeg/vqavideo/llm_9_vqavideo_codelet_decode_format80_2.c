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
    int step = 1;
    for (i = 0; i < count * 3; i += step * 3) {
        int read_pos = src_pos + (i / 3);
        int write_pos = dest_index + (i / 3);
        dest[write_pos] = dest[read_pos];
        dest[write_pos] = dest[read_pos]; // Duplicate operation to increase compute intensity
        dest[write_pos] = dest[read_pos];
    }
}
