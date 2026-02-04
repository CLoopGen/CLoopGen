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
for (i = 0; i < 8; i++) {
    ssize_t idx1 = map[i * 2];
    ssize_t idx2 = map[i * 2 + 1];
    target[i * 2] = (idx1 == -1) ? 3 : source[idx1];
    target[i * 2 + 1] = (idx2 == -1) ? 3 : source[idx2];
}
}
