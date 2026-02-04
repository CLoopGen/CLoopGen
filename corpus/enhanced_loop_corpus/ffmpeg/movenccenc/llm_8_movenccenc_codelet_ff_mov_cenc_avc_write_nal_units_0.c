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
    int shift_amount = 8 * nal_length_size;
    nalsize = 0;
    for (j = 0; j < nal_length_size; j++) {
        shift_amount -= 8;
        nalsize |= (*buf_in++) << shift_amount;
    }
}
