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
    int comp_plane;
    for (i = 0; i < overlay_desc->nb_components; i++) {
        comp_plane = overlay_desc->comp[i].plane + 1;
        if (comp_plane > overlay_planes) {
            overlay_planes = comp_plane;
        }
    }
}
