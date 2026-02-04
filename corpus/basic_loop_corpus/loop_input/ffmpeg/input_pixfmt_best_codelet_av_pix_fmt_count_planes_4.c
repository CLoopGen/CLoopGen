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

AVPixFmtDescriptor *desc;
int i;
int planes[4];

void init_vars() {
    static AVComponentDescriptor comp_data[4] = {
        { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 2, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 3, .step = 1, .offset = 0, .shift = 0, .depth = 8 }
    };

    static AVPixFmtDescriptor desc_data = {
        .name = "test_format",
        .nb_components = 4,
        .log2_chroma_w = 0,
        .log2_chroma_h = 0,
        .flags = 0,
        .comp = {
            { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 2, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 3, .step = 1, .offset = 0, .shift = 0, .depth = 8 }
        },
        .alias = NULL
    };

    desc = &desc_data;
    for (int j = 0; j < 4; j++) {
        planes[j] = 0;
    }
}