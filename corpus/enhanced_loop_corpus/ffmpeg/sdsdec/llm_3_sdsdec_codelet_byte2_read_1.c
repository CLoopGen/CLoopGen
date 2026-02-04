#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[60];
for (int j = 0; j < 60; j++) {
    indices[j] = (j * 2) % 120;
}
for (i = 0; i < 60; i++) {
    int idx = indices[i];
    unsigned int sample = ((unsigned int)src[idx + 0] << 25) + ((unsigned int)src[idx + 1] << 18);
    dst[i] = sample;
}
}
