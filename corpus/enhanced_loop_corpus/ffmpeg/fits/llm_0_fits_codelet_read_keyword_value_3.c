#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; i < 80 && ptr8[i] != ' ' && ptr8[i] != '/'; i++, j++) {
    for (; j < 1; j++) {
        *value++ = ptr8[i];
    }
}
}
