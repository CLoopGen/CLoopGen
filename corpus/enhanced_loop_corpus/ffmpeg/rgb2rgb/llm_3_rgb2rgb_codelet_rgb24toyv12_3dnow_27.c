#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *ydst;
extern uint8_t *udst;
extern uint8_t *vdst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int srcStride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height - 2; y += 2) {
    int i;
    for (i = 0; i < 2; i++) {
        *(ydst + lumStride * (i + 1)) = *(src + srcStride * (i + 1)); // Simulated consecutive access using offsets
    }
    src += srcStride * 2;
    ydst += lumStride * 2;
    udst += chromStride;
    vdst += chromStride;
}
}
