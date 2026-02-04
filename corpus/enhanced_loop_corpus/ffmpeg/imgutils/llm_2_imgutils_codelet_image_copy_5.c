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
extern int i;
extern int planes_nb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process components in reverse order with step of 1)
    int i = desc->nb_components - 1;
    planes_nb = 0;
    for (; i >= 0; i--) {
        int plane_plus1 = desc->comp[i].plane + 1;
        planes_nb = (planes_nb > plane_plus1) ? planes_nb : plane_plus1;
    }
}
