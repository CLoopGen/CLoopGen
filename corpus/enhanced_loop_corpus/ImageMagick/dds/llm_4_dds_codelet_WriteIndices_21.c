#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *indices;
extern ssize_t i;
extern size_t a;
extern size_t b;
extern unsigned char remapped[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    remapped[i] = 0;
    if (a < b)
        remapped[i] = (indices[i] ^ 1) & 3;
    else if (a > b)
        remapped[i] = indices[i];
}
}
