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

static AVPixFmtDescriptor desc_data;
static AVPixFmtDescriptor odesc_data;

AVPixFmtDescriptor *desc = &desc_data;
AVPixFmtDescriptor *odesc = &odesc_data;
int plane;

void init_vars() {
    // Initialize names and alias strings
    desc_data.name = "test_desc";
    desc_data.alias = "alias_desc";
    odesc_data.name = "test_odesc";
    odesc_data.alias = "alias_odesc";

    // Set component counts
    desc_data.nb_components = 3;
    odesc_data.nb_components = 3;

    // Set chroma subsampling values
    desc_data.log2_chroma_w = 0;
    desc_data.log2_chroma_h = 0;
    odesc_data.log2_chroma_w = 0;
    odesc_data.log2_chroma_h = 0;

    // Set flags
    desc_data.flags = 0;
    odesc_data.flags = 0;

    // Initialize component descriptors for valid planes 0,1,2
    for (int i = 0; i < 3; i++) {
        desc_data.comp[i].plane = i;
        desc_data.comp[i].step = 1;
        desc_data.comp[i].offset = i * 100;
        desc_data.comp[i].shift = 0;
        desc_data.comp[i].depth = 8;
        desc_data.comp[i].step_minus1 = 0;
        desc_data.comp[i].depth_minus1 = 7;
        desc_data.comp[i].offset_plus1 = i * 100 + 1;

        odesc_data.comp[i].plane = i + 1;
        odesc_data.comp[i].step = 1;
        odesc_data.comp[i].offset = i * 200;
        odesc_data.comp[i].shift = 1;
        odesc_data.comp[i].depth = 10;
        odesc_data.comp[i].step_minus1 = 0;
        odesc_data.comp[i].depth_minus1 = 9;
        odesc_data.comp[i].offset_plus1 = i * 200 + 1;
    }

    // Ensure comp[3] is also initialized to avoid any potential issues
    desc_data.comp[3].plane = 3;
    desc_data.comp[3].step = 1;
    desc_data.comp[3].offset = 300;
    desc_data.comp[3].shift = 0;
    desc_data.comp[3].depth = 8;
    desc_data.comp[3].step_minus1 = 0;
    desc_data.comp[3].depth_minus1 = 7;
    desc_data.comp[3].offset_plus1 = 301;

    odesc_data.comp[3].plane = 4;
    odesc_data.comp[3].step = 1;
    odesc_data.comp[3].offset = 600;
    odesc_data.comp[3].shift = 1;
    odesc_data.comp[3].depth = 10;
    odesc_data.comp[3].step_minus1 = 0;
    odesc_data.comp[3].depth_minus1 = 9;
    odesc_data.comp[3].offset_plus1 = 601;
}