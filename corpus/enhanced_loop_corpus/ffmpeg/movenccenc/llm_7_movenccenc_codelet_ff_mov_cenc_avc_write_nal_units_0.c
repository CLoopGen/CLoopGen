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
    uint8_t *local_buf = buf_in;
    int local_size = nalsize;
    for (j = 0; j < nal_length_size; j++) {
        local_size = (local_size << 8) | local_buf[j];
        buf_in++; // Update original pointer (WAW dependency preserved via side effect)
    }
    nalsize = local_size; // Final write to shared variable outside loop
}
