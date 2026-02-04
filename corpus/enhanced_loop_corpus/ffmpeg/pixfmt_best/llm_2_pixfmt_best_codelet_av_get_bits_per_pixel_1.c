#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComponentDescriptor {
    int plane;
    int step;
    int offset;
    int shift;
    int depth;
    int step_minus1 __attribute__((deprecated("")));
    int depth_minus1 __attribute__((deprecated("")));
    int offset_plus1 __attribute__((deprecated("")));
} AVComponentDescriptor;

typedef struct AVPixFmtDescriptor {
    const char *name;
    uint8_t nb_components;
    uint8_t log2_chroma_w;
    uint8_t log2_chroma_h;
    uint64_t flags;
    AVComponentDescriptor comp[4];
    const char *alias;
} AVPixFmtDescriptor;

extern  AVPixFmtDescriptor *pixdesc;
extern int c;
extern int bits;
extern int log2_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing components sequentially (0,1,2,3), access them in a strided manner.
    // We simulate stride by accessing with a step of 2, then handling remainder.
    int stride = 2;
    int max_components = pixdesc->nb_components;

    // First pass: even indices with stride
    for (c = 0; c < max_components; c += stride) {
        int s = (c == 1 || c == 2) ? 0 : log2_pixels;
        bits += pixdesc->comp[c].depth << s;
    }
    // Second pass: odd indices to cover all components (indirect-like coverage)
    for (c = 1; c < max_components; c += stride) {
        int s = (c == 1 || c == 2) ? 0 : log2_pixels;
        bits += pixdesc->comp[c].depth << s;
    }
}
