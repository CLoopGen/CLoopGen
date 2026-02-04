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
extern  AVPixFmtDescriptor *odesc;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (plane = 0; plane < 1; plane++) {
        int p = desc->comp[plane].plane;
        p = odesc->comp[plane].plane;
    }
    for (plane = 1; plane < 2; plane++) {
        int p = desc->comp[plane].plane;
        p = odesc->comp[plane].plane;
    }
    for (plane = 2; plane < 3; plane++) {
        int p = desc->comp[plane].plane;
        p = odesc->comp[plane].plane;
    }
}
