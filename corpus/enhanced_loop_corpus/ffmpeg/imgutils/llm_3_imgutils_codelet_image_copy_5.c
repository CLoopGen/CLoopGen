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
    // Variant 2: Indirect memory access using an index map (simulating non-linear access pattern)
    int index_map[4] = {0, 2, 1, 3}; // Define a fixed reordering of component indices
    planes_nb = 0;
    for (i = 0; i < desc->nb_components; i++) {
        int mapped_idx = index_map[i]; // Use mapped index for indirect access
        int plane_plus1 = desc->comp[mapped_idx].plane + 1;
        planes_nb = (planes_nb > plane_plus1) ? planes_nb : plane_plus1;
    }
}
