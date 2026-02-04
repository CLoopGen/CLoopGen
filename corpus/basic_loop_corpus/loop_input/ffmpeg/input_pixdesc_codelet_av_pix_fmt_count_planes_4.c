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

static AVPixFmtDescriptor desc_instance;
AVPixFmtDescriptor *desc = &desc_instance;

int i;
int planes[4];

void init_vars() {
    // Initialize descriptor name and metadata
    desc->nb_components = 3;
    desc->log2_chroma_w = 0;
    desc->log2_chroma_h = 0;
    desc->flags = 0;
    desc->alias = NULL;

    // Ensure comp[i].plane is within [0,3] to not exceed planes array bounds
    desc->comp[0].plane = 0;
    desc->comp[1].plane = 1;
    desc->comp[2].plane = 2;
    desc->comp[3].plane = 3; // Will not be accessed since nb_components=3

    // Initialize other fields (required to avoid undefined behavior)
    for (int j = 0; j < 4; j++) {
        desc->comp[j].step = j + 1;
        desc->comp[j].offset = 0;
        desc->comp[j].shift = 0;
        desc->comp[j].depth = 8;
        desc->comp[j].step_minus1 = desc->comp[j].step - 1;
        desc->comp[j].depth_minus1 = desc->comp[j].depth - 1;
        desc->comp[j].offset_plus1 = desc->comp[j].offset + 1;
    }

    // Initialize planes array
    for (int j = 0; j < 4; j++) {
        planes[j] = 0;
    }

    // Initialize loop index
    i = 0;
}