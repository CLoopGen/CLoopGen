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

int i;
int has_plane[4];
AVPixFmtDescriptor *desc;

void init_vars() {
    static AVPixFmtDescriptor local_desc = {
        .name = "test_format",
        .nb_components = 3,
        .log2_chroma_w = 1,
        .log2_chroma_h = 1,
        .flags = 0,
        .comp = {
            { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 2, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8 }
        },
        .alias = "test_alias"
    };

    desc = &local_desc;
    
    for (int j = 0; j < 4; j++) {
        has_plane[j] = 0;
    }
}