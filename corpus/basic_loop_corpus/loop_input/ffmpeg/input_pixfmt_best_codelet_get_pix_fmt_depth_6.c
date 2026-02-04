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

int *min;
int *max;
AVPixFmtDescriptor *desc;
int i;

void init_vars() {
    min = (int*)malloc(sizeof(int));
    max = (int*)malloc(sizeof(int));
    desc = (AVPixFmtDescriptor*)malloc(sizeof(AVPixFmtDescriptor));

    *min = 1000;
    *max = 0;

    desc->nb_components = 4;
    desc->comp[0].depth = 8;
    desc->comp[1].depth = 10;
    desc->comp[2].depth = 12;
    desc->comp[3].depth = 9;
}