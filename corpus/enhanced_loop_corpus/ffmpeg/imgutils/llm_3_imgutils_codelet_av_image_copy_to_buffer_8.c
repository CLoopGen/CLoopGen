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
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Use an explicit index mapping table to access the comp array indirectly.
    // This simulates scenarios where access patterns are data-dependent or non-sequential.
    int index_map[4] = {0, 2, 1, 3}; // Arbitrary permutation: reorder access sequence
    int n = desc->nb_components;
    nb_planes = 0; // Reset accumulator
    for (i = 0; i < n; i++) {
        int mapped_idx = index_map[i]; // Indirect access via lookup
        if (mapped_idx < 4 && i < 4) { // Bound checks to stay within comp[4]
            nb_planes = (desc->comp[mapped_idx].plane > nb_planes) ? desc->comp[mapped_idx].plane : nb_planes;
        }
    }
}
