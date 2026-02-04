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
    nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        if (buf + *buf_index != NULL) {
            nalsize = (nalsize << 8) | buf[(*buf_index)++];
        }
    }
}
