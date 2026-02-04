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
int nb_planes;
AVPixFmtDescriptor *desc;

void init_vars() {
    static const char name[] = "test_format";
    static const char alias[] = "test_alias";

    static AVPixFmtDescriptor descriptor = {
        .name = name,
        .nb_components = 4,
        .log2_chroma_w = 0,
        .log2_chroma_h = 0,
        .flags = 0,
        .comp = {
            { .plane = 0, .step = 1, .offset = 0, .shift = 0, .depth = 8, .step_minus1 = 0, .depth_minus1 = 7, .offset_plus1 = 1 },
            { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8, .step_minus1 = 0, .depth_minus1 = 7, .offset_plus1 = 1 },
            { .plane = 2, .step = 1, .offset = 0, .shift = 0, .depth = 8, .step_minus1 = 0, .depth_minus1 = 7, .offset_plus1 = 1 },
            { .plane = 1, .step = 1, .offset = 0, .shift = 0, .depth = 8, .step_minus1 = 0, .depth_minus1 = 7, .offset_plus1 = 1 }
        },
        .alias = alias
    };

    desc = &descriptor;
    nb_planes = 0;
    i = 0;
}