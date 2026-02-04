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
    int local_min = *min;
    int local_max = *max;
    for (i = 0; i < desc->nb_components; i++) {
        local_min = (desc->comp[i].depth < local_min) ? desc->comp[i].depth : local_min;
        local_max = (desc->comp[i].depth > local_max) ? desc->comp[i].depth : local_max;
    }
    *min = local_min;
    *max = local_max;
}
