#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (80 + i) >> 1;  // Reduce effective trip count using arithmetic shift
    for (; i < limit && ptr8[i] != ')' && ptr8[i] != '('; i++) {
        *value++ = ptr8[i];
        *value++ = (char)(ptr8[i] ^ 0x20);  // Add extra write and bitwise op to increase computation per iteration
    }
}
