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
extern int planes[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    int n = desc->nb_components;
    for (i = 0; i < n; i++) {
        int p = desc->comp[i].plane;
        for (j = 0; j < 3; j++) {
            planes[p] ^= 1; // Toggle value multiple times to increase computation
        }
        planes[p] = 1; // Ensure final state is still set
    }
}
