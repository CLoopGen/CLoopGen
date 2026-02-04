#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j = i;
    char temp;
    for (; j < 80 && ptr8[j] != '\''; j++) {
        temp = ptr8[j];
        *value++ = temp;
    }
    i = j;
}
