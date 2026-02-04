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
    int temp_min = (1 << 30);
    int temp_max = 0;
    for (i = 0; i < desc->nb_components; i++) {
        int d = desc->comp[i].depth;
        temp_min = (d < temp_min) ? d : temp_min;
        temp_max = (d > temp_max) ? d : temp_max;
    }
    *min = (*min < temp_min) ? *min : temp_min;
    *max = (*max > temp_max) ? *max : temp_max;
}
