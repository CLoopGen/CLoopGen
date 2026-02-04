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

AVPixFmtDescriptor *pixdesc;
int c;
int bits;
int log2_pixels;

void init_vars() {
    static AVComponentDescriptor comp_data[4] = {
        { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 2, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
        { .plane = 3, .step = 1, .offset = 0, .shift = 0, .depth = 8 }
    };

    static const char name[] = "test_format";
    static const char alias[] = "test_alias";

    static AVPixFmtDescriptor desc = {
        .name = name,
        .nb_components = 3,
        .log2_chroma_w = 0,
        .log2_chroma_h = 0,
        .flags = 0,
        .comp = {
            { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 2, .step = 1, .offset = 0, .shift = 0, .depth = 8 },
            { .plane = 3, .step = 1, .offset = 0, .shift = 0, .depth = 8 }
        },
        .alias = alias
    };

    pixdesc = &desc;
    c = 0;
    bits = 0;
    log2_pixels = 10;
}