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
    for (i = 3; i >= 0; i--) {
        const AVComponentDescriptor *comp = &(pixdesc->comp[i]);
        int plane = comp->plane;
        int step = comp->step;
        int current_max = max_pixsteps[plane];
        if (step > current_max) {
            max_pixsteps[plane] = step;
            if (max_pixstep_comps)
                max_pixstep_comps[plane] = i;
        } else if (step == current_max && max_pixstep_comps) {
            if (i > max_pixstep_comps[plane]) {
                max_pixstep_comps[plane] = i;
            }
        }
    }
}
