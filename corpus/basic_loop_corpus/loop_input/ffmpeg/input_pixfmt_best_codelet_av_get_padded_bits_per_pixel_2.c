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
int log2_pixels;
int steps[4];

static AVComponentDescriptor comp_data[4];
static AVPixFmtDescriptor pixdesc_storage;

void init_vars() {
    for (int i = 0; i < 4; i++) {
        comp_data[i].plane = i % 3;
        comp_data[i].step = 1 + i;
        comp_data[i].offset = i * 10;
        comp_data[i].shift = 0;
        comp_data[i].depth = 8 + i * 8;
        comp_data[i].step_minus1 = comp_data[i].step - 1;
        comp_data[i].depth_minus1 = comp_data[i].depth - 1;
        comp_data[i].offset_plus1 = comp_data[i].offset + 1;
    }

    pixdesc_storage.name = "test_format";
    pixdesc_storage.nb_components = 3;
    pixdesc_storage.log2_chroma_w = 0;
    pixdesc_storage.log2_chroma_h = 0;
    pixdesc_storage.flags = 0;
    pixdesc_storage.comp[0] = comp_data[0];
    pixdesc_storage.comp[1] = comp_data[1];
    pixdesc_storage.comp[2] = comp_data[2];
    pixdesc_storage.comp[3] = comp_data[3];
    pixdesc_storage.alias = NULL;

    pixdesc = &pixdesc_storage;
    log2_pixels = 3;

    for (int i = 0; i < 4; i++) {
        steps[i] = 0;
    }
}