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
    int local_min = 8;
    int local_max = 0;
    int components = desc->nb_components;
    for (i = 0; i < components; i += 2) {
        int depth1 = desc->comp[i].depth;
        local_min = (depth1 < local_min) ? depth1 : local_min;
        local_max = (depth1 > local_max) ? depth1 : local_max;

        if (i + 1 < components) {
            int depth2 = desc->comp[i + 1].depth;
            local_min = (depth2 < local_min) ? depth2 : local_min;
            local_max = (depth2 > local_max) ? depth2 : local_max;
        }
    }
    *min = local_min;
    *max = local_max;
}
