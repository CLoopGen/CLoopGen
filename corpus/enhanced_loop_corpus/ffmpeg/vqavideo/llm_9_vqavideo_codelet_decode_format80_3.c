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
    int limit = count * 4;
    for (i = 0; i < limit; i += 4) {
        int read_pos = src_pos + (i / 4);
        int write_pos = dest_index + (i / 4);
        dest[write_pos] = (dest[read_pos] + step) ^ 0xAA;
    }
}
