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

extern int i;
extern  AVPixFmtDescriptor *desc;
extern int planes_nb;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    const AVComponentDescriptor *comp_base = desc->comp;
    int k;
    for (k = 0; k < desc->nb_components; k += 1) {
        int current_plane = (comp_base + k)->plane + 1;
        if (current_plane > planes_nb) {
            planes_nb = current_plane;
        }
    }
}
