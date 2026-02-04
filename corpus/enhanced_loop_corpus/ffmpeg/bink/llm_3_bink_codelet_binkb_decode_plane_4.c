#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[64];
    for (int j = 0; j < 64; j++) {
        indices[j] = (j & 7) * 8 + (j >> 3);
    }
    for (i = 0; i < 64; i++) {
        int mapped_index = indices[i];
        coordmap[mapped_index] = (i & 7) + (i >> 3) * stride;
    }
}
