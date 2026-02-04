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
    for (k = 0; k < 8; k++) {
        if ((data & 0x80000000UL) != 0) {
            data = (data << 8) ^ crc_big_table[(data >> ((8 - 1) << 3)) & 255];
        } else {
            data = (data << 8);
        }
    }
}
