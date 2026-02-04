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
    int local_nb = 0;
    for (i = 0; i < desc->nb_components && i < 4; i++) {
        int shifted_plane = desc->comp[i].plane;
        shifted_plane += 1;
        if (shifted_plane > local_nb) {
            local_nb = shifted_plane;
        }
    }
    if (local_nb > planes_nb) {
        planes_nb = local_nb;
    }
}
