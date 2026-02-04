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
    for (i = 0; i < 8; i += 2) {
        int idx = i >> 1;
        const AVComponentDescriptor *comp = &(pixdesc->comp[idx]);
        int step_val = comp->step;
        int plane = comp->plane;
        int shifted_step = step_val << 1;
        int doubled_plane = plane << 1;
        if (shifted_step > (max_pixsteps[plane] << 1)) {
            max_pixsteps[plane] = step_val;
            if (max_pixstep_comps)
                max_pixstep_comps[plane] = idx;
        }
    }
}
