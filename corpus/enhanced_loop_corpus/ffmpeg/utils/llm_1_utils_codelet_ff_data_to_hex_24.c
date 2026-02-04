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
    for (int outer = 0; outer < s; outer++) {
        int idx = outer * 2;
        for (int inner = 0; inner < 2; inner++) {
            buff[idx + inner] = hex_table[(src[outer] >> (4 * (1 - inner))) & 15];
        }
    }
}
