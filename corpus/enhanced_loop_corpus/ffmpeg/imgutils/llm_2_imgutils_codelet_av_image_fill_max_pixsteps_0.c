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

extern int max_pixsteps[4];
extern int max_pixstep_comps[4];
extern  AVPixFmtDescriptor *pixdesc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using array indexing with stride simulation
    for (i = 0; i < 4; i++) {
        const AVComponentDescriptor comp = pixdesc->comp[i]; // Local copy to avoid pointer indirection
        int plane = comp.plane;
        int step = comp.step;
        if (step > max_pixsteps[plane]) {
            max_pixsteps[plane] = step;
            if (max_pixstep_comps)
                max_pixstep_comps[plane] = i;
        }
    }
}
