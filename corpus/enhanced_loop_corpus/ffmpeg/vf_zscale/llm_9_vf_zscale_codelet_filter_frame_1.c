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

extern  AVPixFmtDescriptor *desc;
extern  AVPixFmtDescriptor *odesc;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (plane = 0; plane < 2; plane++) {
    int p1 = desc->comp[plane].plane;
    int p2 = odesc->comp[plane].plane;
    int diff = (p1 > p2) ? (p1 - p2) : (p2 - p1);
    if (diff > 0) {
        for (int shift = 0; shift < 2; shift++) {
            p1 <<= 1;
            p2 >>= 1;
        }
    }
}
}
