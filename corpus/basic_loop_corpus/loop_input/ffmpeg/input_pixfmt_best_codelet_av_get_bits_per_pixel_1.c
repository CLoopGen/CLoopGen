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
        {0, 1, 0, 0, 8, 0, 7, 1},
        {1, 1, 0, 0, 8, 0, 7, 1},
        {2, 1, 0, 0, 8, 0, 7, 1},
        {3, 1, 0, 0, 8, 0, 7, 1}
    };

    static const char name[] = "test_format";
    static const char alias[] = "test_alias";

    static AVPixFmtDescriptor desc = {
        name,
        3,
        1,
        1,
        0,
        {{0,1,0,0,8,0,7,1},{1,1,0,0,10,0,9,1},{2,1,0,0,10,0,9,1},{3,1,0,0,8,0,7,1}},
        alias
    };

    pixdesc = &desc;
    c = 0;
    bits = 0;
    log2_pixels = 10;
}