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
    if (desc->nb_components > 0) {
        i = 0;
        for (; i < desc->nb_components; ) {
            *min = ((desc->comp[i].depth) > (*min) ? (*min) : (desc->comp[i].depth));
            *max = ((desc->comp[i].depth) > (*max) ? (desc->comp[i].depth) : (*max));
            i++;
        }
    }
}
