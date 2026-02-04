#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *row;
extern uint32_t pixels;
extern  uint16_t *gamma_lut;
extern uint32_t i;
extern unsigned char *px;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < pixels * 3; i++) {
        uint32_t byte_index = i;
        unsigned char original_value = row[byte_index];
        row[byte_index] = (uint8_t)(gamma_lut[original_value] & 0xFF);
    }
}
