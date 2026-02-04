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
    // Variant 1: Consecutive memory access with pointer arithmetic
    AVComponentDescriptor *comp = desc->comp;
    int nb_components = desc->nb_components;
    int min_val = *min;
    int max_val = *max;
    for (i = 0; i < nb_components; i++) {
        int depth = comp[i].depth;
        min_val = (depth < min_val) ? depth : min_val;
        max_val = (depth > max_val) ? depth : max_val;
    }
    *min = min_val;
    *max = max_val;
}
