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
    for (int j = 0; j < s; j++) {
        for (int k = 0; k < 2; k++) {
            if (k == 0) {
                buff[j * 2] = hex_table[src[j] >> 4];
            } else {
                buff[j * 2 + 1] = hex_table[src[j] & 15];
            }
        }
    }
}
