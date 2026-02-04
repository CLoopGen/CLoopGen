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
    for (i = 0; i < s * 2; i += 2) {
        uint8_t val = src[i / 2];
        buff[i] = hex_table[val >> 4];
        buff[i + 1] = hex_table[val & 15];
    }
}
