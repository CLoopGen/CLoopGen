#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint64_t z_word_t;

extern  uint32_t crc_table[];
extern z_word_t data;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 16; k += 2) {
        data = (data >> 8) ^ crc_table[data & 255];
        data = (data >> 8) ^ crc_table[data & 255];
    }
}
