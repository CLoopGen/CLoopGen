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
    int outer = 0;
    int inner;
    if (nal_length_size <= 0) return;
    while (outer < 1) {
        for (inner = 0; inner < nal_length_size; inner++) {
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        }
        outer++;
    }
}
