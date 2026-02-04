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
    for (outer = 0; outer < nal_length_size / 2 + nal_length_size % 2; outer++) {
        for (inner = 0; inner < 2; inner++) {
            int idx = outer * 2 + inner;
            if (idx < nal_length_size)
                nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        }
    }
}
