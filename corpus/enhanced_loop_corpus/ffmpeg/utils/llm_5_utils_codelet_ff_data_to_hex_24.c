#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buff;
extern  uint8_t *src;
extern int s;
extern int i;
extern  char *hex_table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < s; i++) {
        uint8_t upper = src[i] >> 4;
        uint8_t lower = src[i] & 15;
        buff[i * 2] = hex_table[upper];
        if (lower != 0 || src[i] == 0) {
            buff[i * 2 + 1] = hex_table[lower];
        } else {
            buff[i * 2 + 1] = '0';
        }
    }
}
