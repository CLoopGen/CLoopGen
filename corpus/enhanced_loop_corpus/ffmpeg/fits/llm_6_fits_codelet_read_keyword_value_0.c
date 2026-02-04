#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *keyword;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 0; i < 8 && ptr8[i] != ' '; i++) {
        temp = ptr8[i];
        keyword[i] = temp;
    }
}
