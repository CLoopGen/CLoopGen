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
    int j, i_save = i;
    for (i = 0; i < outer; i++) {
        for (int j = 0; j < nal_length_size; j++) {
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        }
    }
    i = i_save;
}
