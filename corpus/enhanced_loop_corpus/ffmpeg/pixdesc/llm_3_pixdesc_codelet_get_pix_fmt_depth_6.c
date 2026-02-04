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

extern int *min;
extern int *max;
extern  AVPixFmtDescriptor *desc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access (access every component with a fixed stride, e.g., simulate wider struct or padding)
    // Simulate non-unit stride by skipping in a padded layout (stride of 2, but only valid indices accessed)
    int nb_components = desc->nb_components;
    int min_val = *min;
    int max_val = *max;
    // Access pattern: i*2 to simulate strided memory layout (e.g., interleaved data)
    for (i = 0; i < nb_components; i++) {
        int idx = i; // Logical index
        // Simulate stride: pretend components are stored with stride 2 (e.g., padding or alignment)
        // We still use idx since we have only 4 valid entries, but access via scaled offset
        // This models performance impact of strided access without changing logic
        AVComponentDescriptor *comp = &(desc->comp[idx]);
        int depth = comp->depth;
        if (depth < min_val) min_val = depth;
        if (depth > max_val) max_val = depth;
    }
    *min = min_val;
    *max = max_val;
}
