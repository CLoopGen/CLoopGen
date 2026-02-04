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
extern  int chromWidth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    int i;
    // Modify access pattern to use strided iteration: process every second element first, then fill gaps
    // First pass: handle all "0th" positions (luma even indices and chroma)
    for (i = 0; i < chromWidth; i++) {
        int src_idx = 4 * i;
        int y_idx = 2 * i;

        ydst[y_idx] = src[src_idx];         // ydst[2*i+0]
        udst[i] = src[src_idx + 1];
        vdst[i] = src[src_idx + 3];
    }
    // Second part of first row: fill luma odd indices (can be combined but kept separate for clarity)
    for (i = 0; i < chromWidth; i++) {
        int src_idx = 4 * i;
        int y_idx = 2 * i + 1;

        ydst[y_idx] = src[src_idx + 2];
    }

    ydst += lumStride;
    src += srcStride;

    // Process second row: only luma values, split into two strided-like phases
    for (i = 0; i < chromWidth; i++) {
        int src_idx = 4 * i;
        int y_idx = 2 * i;

        ydst[y_idx] = src[src_idx];
    }
    for (i = 0; i < chromWidth; i++) {
        int src_idx = 4 * i;
        int y_idx = 2 * i + 1;

        ydst[y_idx] = src[src_idx + 2];
    }

    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;
}
}
