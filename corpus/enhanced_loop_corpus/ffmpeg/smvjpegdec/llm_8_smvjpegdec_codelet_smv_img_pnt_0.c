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

extern  AVPixFmtDescriptor *desc;
extern int i;
extern int planes_nb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    int local_planes_nb = planes_nb;
    for (; i < (int)desc->nb_components * 2; i += 2) {
        if ((i + 1) < desc->nb_components) {
            int plane1 = desc->comp[i].plane + 1;
            int plane2 = desc->comp[i + 1].plane + 1;
            local_planes_nb = (local_planes_nb > plane1) ? local_planes_nb : plane1;
            local_planes_nb = (local_planes_nb > plane2) ? local_planes_nb : plane2;
        } else if (i < desc->nb_components) {
            int plane = desc->comp[i].plane + 1;
            local_planes_nb = (local_planes_nb > plane) ? local_planes_nb : plane;
        }
    }
    planes_nb = local_planes_nb;
}
