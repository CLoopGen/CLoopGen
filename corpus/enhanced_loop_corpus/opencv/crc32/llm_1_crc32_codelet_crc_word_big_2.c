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
    int inner_k;
    for (inner_k = 0; inner_k < 1; inner_k++)
        data = (data << 8) ^ crc_big_table[(data >> ((8 - 1) << 3)) & 255];
}
}
