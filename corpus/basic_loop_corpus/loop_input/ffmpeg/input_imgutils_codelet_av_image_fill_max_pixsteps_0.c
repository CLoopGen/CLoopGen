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

int max_pixsteps[4];
int max_pixstep_comps[4];
AVPixFmtDescriptor *pixdesc;
int i;

void init_vars() {
    pixdesc = (AVPixFmtDescriptor *)calloc(1, sizeof(AVPixFmtDescriptor));
    if (!pixdesc) {
        return;
    }

    pixdesc->nb_components = 4;
    pixdesc->log2_chroma_w = 0;
    pixdesc->log2_chroma_h = 0;
    pixdesc->flags = 0;
    pixdesc->name = "test_format";
    pixdesc->alias = NULL;

    for (int j = 0; j < 4; j++) {
        pixdesc->comp[j].plane = j % 3;
        pixdesc->comp[j].step = (j + 1) * 8;
        pixdesc->comp[j].offset = 0;
        pixdesc->comp[j].shift = 0;
        pixdesc->comp[j].depth = 8;
        pixdesc->comp[j].step_minus1 = (j + 1) * 8 - 1;
        pixdesc->comp[j].depth_minus1 = 7;
        pixdesc->comp[j].offset_plus1 = 1;
    }

    for (int j = 0; j < 4; j++) {
        max_pixsteps[j] = 0;
    }
    for (int j = 0; j < 4; j++) {
        max_pixstep_comps[j] = -1;
    }

    i = 0;
}