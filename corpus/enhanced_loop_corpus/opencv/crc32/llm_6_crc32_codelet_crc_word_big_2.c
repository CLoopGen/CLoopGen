#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned long z_word_t;

extern  z_word_t crc_big_table[];
extern z_word_t data;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    z_word_t temp = data;
    for (k = 0; k < 8; k++) {
        z_word_t index = (temp >> ((8 - 1) << 3)) & 255;
        temp = (temp << 8) ^ crc_big_table[index];
    }
    data = temp;
}
