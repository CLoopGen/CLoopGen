#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf;
extern int *buf_index;
extern int i;
extern int nalsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = 1;
    int j, k;
    for (j = 0; j < outer; j++) {
        for (k = 0; k < nal_length_size; k++) {
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        }
    }
}
