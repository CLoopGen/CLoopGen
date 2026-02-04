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

extern  AVPixFmtDescriptor *main_desc;
extern int main_planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2, forward pass with bounds check)
    int n = main_desc->nb_components;
    // First handle even indices
    for (int i = 0; i < n; i += 2)
        main_planes = (main_planes > main_desc->comp[i].plane + 1) ? main_planes : main_desc->comp[i].plane + 1;
    // Then handle odd indices in a separate iteration
    for (int i = 1; i < n; i += 2)
        main_planes = (main_planes > main_desc->comp[i].plane + 1) ? main_planes : main_desc->comp[i].plane + 1;
}
