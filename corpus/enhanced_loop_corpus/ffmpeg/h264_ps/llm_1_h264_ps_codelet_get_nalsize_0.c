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
    for (int depth1 = 0; depth1 < nal_length_size; depth1++) {
        for (int depth2 = 0; depth2 < 1; depth2++) {
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        }
    }
}
