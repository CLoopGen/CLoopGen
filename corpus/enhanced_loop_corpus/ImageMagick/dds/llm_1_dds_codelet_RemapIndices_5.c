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
for (i = 0; i < 4; i++) {
    for (ssize_t j = 0; j < 4; j++) {
        ssize_t idx = i * 4 + j;
        if (map[idx] == -1)
            target[idx] = 3;
        else
            target[idx] = source[map[idx]];
    }
}
}
