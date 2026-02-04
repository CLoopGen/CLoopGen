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

AVPixFmtDescriptor *main_desc;
int main_planes;

void init_vars() {
    static AVComponentDescriptor comp_data[4] = {
        { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 2, .step = 1, .offset = 0, .shift = 0, .depth = 8 }
    };

    static AVPixFmtDescriptor desc = {
        .name = "test_format",
        .nb_components = 3,
        .log2_chroma_w = 1,
        .log2_chroma_h = 1,
        .flags = 0,
        .comp = { {0} },
        .alias = NULL
    };

    for (int i = 0; i < 4; i++) {
        desc.comp[i] = comp_data[i];
    }

    main_desc = &desc;
    main_planes = 0;
}