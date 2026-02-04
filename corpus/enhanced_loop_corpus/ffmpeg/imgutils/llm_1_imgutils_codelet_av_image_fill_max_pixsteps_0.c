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
// Reduced effective loop depth by unrolling the original loop assuming small fixed bound
const AVComponentDescriptor *comp0 = &(pixdesc->comp[0]);
if (comp0->step > max_pixsteps[comp0->plane]) {
    max_pixsteps[comp0->plane] = comp0->step;
    if (max_pixstep_comps)
        max_pixstep_comps[comp0->plane] = 0;
}

const AVComponentDescriptor *comp1 = &(pixdesc->comp[1]);
if (comp1->step > max_pixsteps[comp1->plane]) {
    max_pixsteps[comp1->plane] = comp1->step;
    if (max_pixstep_comps)
        max_pixstep_comps[comp1->plane] = 1;
}

const AVComponentDescriptor *comp2 = &(pixdesc->comp[2]);
if (comp2->step > max_pixsteps[comp2->plane]) {
    max_pixsteps[comp2->plane] = comp2->step;
    if (max_pixstep_comps)
        max_pixstep_comps[comp2->plane] = 2;
}

const AVComponentDescriptor *comp3 = &(pixdesc->comp[3]);
if (comp3->step > max_pixsteps[comp3->plane]) {
    max_pixsteps[comp3->plane] = comp3->step;
    if (max_pixstep_comps)
        max_pixstep_comps[comp3->plane] = 3;
}
}
