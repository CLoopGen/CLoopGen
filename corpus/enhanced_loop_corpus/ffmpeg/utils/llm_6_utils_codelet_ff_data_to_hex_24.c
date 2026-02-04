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
    uint8_t temp_val;
    for (i = 0; i < s; i++) {
        temp_val = src[i];
        buff[i * 2] = hex_table[temp_val >> 4];
        buff[i * 2 + 1] = hex_table[temp_val & 15];
    }
}
