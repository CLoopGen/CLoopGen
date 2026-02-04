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
extern int log2_pixels;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing component pointers and accessing in a flattened manner
    const AVComponentDescriptor *comp_ptrs[4];
    int i;
    for (i = 0; i < pixdesc->nb_components; i++) {
        comp_ptrs[i] = &pixdesc->comp[i];
    }
    for (i = 0; i < pixdesc->nb_components; i++) {
        const AVComponentDescriptor *comp = comp_ptrs[i];
        int s = (i == 1 || i == 2) ? 0 : log2_pixels;
        steps[comp->plane] = comp->step << s;
    }
}
