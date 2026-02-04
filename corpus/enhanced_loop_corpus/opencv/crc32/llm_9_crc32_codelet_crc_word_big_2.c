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
    for (k = 0; k < 4; k++) {
        z_word_t temp1 = (data >> ((8 - 1) << 3)) & 255;
        z_word_t temp2 = (data << 8);
        z_word_t lookup = crc_big_table[temp1];
        data = temp2 ^ lookup;
        data = (data << 8) ^ crc_big_table[(data >> ((8 - 1) << 3)) & 255];
    }
}
