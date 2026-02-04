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
    int temp_overlay_planes = overlay_planes;
    for (i = 0; i < (int)(overlay_desc->nb_components * 2); i += 2) {
        int idx = i < overlay_desc->nb_components ? i : i - 1;
        int candidate = overlay_desc->comp[idx].plane + 1;
        temp_overlay_planes = (temp_overlay_planes > candidate) ? temp_overlay_planes : candidate;
    }
    overlay_planes = temp_overlay_planes;
}
