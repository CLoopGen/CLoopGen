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
for (i = 0; i < 16; i += 2) {
    if (map[i] == -1)
        target[i] = 3;
    else
        target[i] = source[map[i]];
    if (i + 1 < 16) {
        if (map[i + 1] == -1)
            target[i + 1] = 3;
        else
            target[i + 1] = source[map[i + 1]];
    }
}
}
