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

static char static_name_buffer[] = "test_format";
static char static_alias_buffer[] = "alias";

static AVComponentDescriptor static_comp_data[4] = {
    {0, 1, 0, 0, 8, 0, 7, 1},
    {1, 1, 0, 0, 8, 0, 7, 1},
    {1, 1, 0, 0, 8, 0, 7, 1},
    {2, 1, 0, 0, 8, 0, 7, 1}
};

static AVPixFmtDescriptor static_desc = {
    .name = static_name_buffer,
    .nb_components = 3,
    .log2_chroma_w = 0,
    .log2_chroma_h = 0,
    .flags = 0,
    .comp = {
        {0, 1, 0, 0, 8, 0, 7, 1},
        {1, 1, 0, 0, 8, 0, 7, 1},
        {1, 1, 0, 0, 8, 0, 7, 1},
        {2, 1, 0, 0, 8, 0, 7, 1}
    },
    .alias = static_alias_buffer
};

AVPixFmtDescriptor *desc = &static_desc;
int i;
int planes_nb;

void init_vars() {
    i = 0;
    planes_nb = 0;
}