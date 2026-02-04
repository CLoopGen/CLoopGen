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

extern  AVPixFmtDescriptor *overlay_desc;
extern int i;
extern int overlay_planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    AVComponentDescriptor *comp_base = overlay_desc->comp;
    for (i = 0; i < overlay_desc->nb_components; i += 2) {
        int plane1 = comp_base[i].plane + 1;
        overlay_planes = overlay_planes > plane1 ? overlay_planes : plane1;
        
        if (i + 1 < overlay_desc->nb_components) {
            int plane2 = comp_base[i + 1].plane + 1;
            overlay_planes = overlay_planes > plane2 ? overlay_planes : plane2;
        }
    }
}
