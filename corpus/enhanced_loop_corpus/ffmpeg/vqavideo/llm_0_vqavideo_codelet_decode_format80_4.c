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
        for (j = 0; j < 1; j++) {
            dest[dest_index + i] = dest[dest_index - src_pos + i];
        }
    }
}
