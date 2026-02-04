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
    int j, k;
    if (count > 0) {
        for (j = 0; j < count; j += 2) {
            for (k = 0; k < 2 && (j + k) < count; k++) {
                dest[dest_index + j + k] = dest[src_pos + j + k];
            }
        }
    }
}
