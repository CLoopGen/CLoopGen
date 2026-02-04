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



void loop(){
    if (pixdesc->nb_components > 0) {
        c = 0;
        int s = c == 1 || c == 2 ? 0 : log2_pixels;
        bits += pixdesc->comp[c].depth << s;
        for (c = 1; c < pixdesc->nb_components; c++) {
            int s = c == 1 || c == 2 ? 0 : log2_pixels;
            bits += pixdesc->comp[c].depth << s;
        }
    }
}
