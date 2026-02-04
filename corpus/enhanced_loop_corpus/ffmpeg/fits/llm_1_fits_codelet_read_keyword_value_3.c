#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int level1 = 0; level1 < 1 && i < 80 && ptr8[i] != ' ' && ptr8[i] != '/'; level1++) {
    for (; i < 80 && ptr8[i] != ' ' && ptr8[i] != '/'; i++) {
        *value++ = ptr8[i];
    }
}
}
