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
    for (i = 0; i < nal_length_size; i++) {
        int inner_iter = 1;
        for (int k = 0; k < inner_iter; k++)
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }
}
