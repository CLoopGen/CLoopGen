#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf_in;
extern int nalsize;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_nalsize = nalsize;
    for (j = 0; j < nal_length_size; j++) {
        temp_nalsize = (temp_nalsize << 8) | buf_in[j];
    }
    nalsize = temp_nalsize;
}
