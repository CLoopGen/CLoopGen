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

extern int *min;
extern int *max;
extern  AVPixFmtDescriptor *desc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    AVComponentDescriptor *comp_base = desc->comp;
    int stride = 1; // Strided access pattern (could be modified for different strides, but safely kept as 1 here for correctness)
    for (i = 0; i < desc->nb_components; i += stride) {
        AVComponentDescriptor *c = &comp_base[i * stride];
        *min = (c->depth < *min) ? c->depth : *min;
        *max = (c->depth > *max) ? c->depth : *max;
    }
}
