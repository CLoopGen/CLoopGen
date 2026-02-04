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
    int j;
    for (j = 0; j < nal_length_size; j++) {
        nalsize = 0;
        for (i = 0; i <= j; i++)
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        if (j < nal_length_size - 1)
            *buf_index -= (j + 1);
    }
}
