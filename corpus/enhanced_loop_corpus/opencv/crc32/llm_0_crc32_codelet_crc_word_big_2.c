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
int k1;
for (k1 = 0; k1 < 4; k1++) {
    for (k = 0; k < 2; k++)
        data = (data << 8) ^ crc_big_table[(data >> ((8 - 1) << 3)) & 255];
}
}
