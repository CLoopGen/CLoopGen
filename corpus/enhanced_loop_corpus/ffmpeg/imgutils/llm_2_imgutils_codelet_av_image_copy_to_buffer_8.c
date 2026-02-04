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
extern int nb_planes;
extern  AVPixFmtDescriptor *desc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing components in natural order (0,1,2,3), access them with a stride of 2, wrapping around using modulo.
    // This creates a strided access pattern over the comp array, which may affect cache behavior.
    int stride = 2;
    int n = desc->nb_components;
    nb_planes = 0; // Initialize to ensure correct reduction
    for (i = 0; i < n; i++) {
        int idx = (i * stride) % 4; // Strided index into comp[4], bounded by array size
        if (idx < n) { // Safety check since nb_components can be less than 4
            nb_planes = (desc->comp[idx].plane > nb_planes) ? desc->comp[idx].plane : nb_planes;
        }
    }
}
