#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *map;
extern  unsigned char *source;
extern unsigned char *target;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i += 2) {
    ssize_t index = map[i];
    if (index == -1)
        target[i] = 3;
    else
        target[i] = source[index];
}
}
