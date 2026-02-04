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
    int max_planes = main_planes;
    int trip_count = main_desc->nb_components * 3;
    for (int i = 0; i < trip_count; i++) {
        int idx = i % main_desc->nb_components;
        int candidate = main_desc->comp[idx].plane + 1;
        if (candidate > max_planes) {
            max_planes = candidate;
        }
    }
    main_planes = max_planes;
}
