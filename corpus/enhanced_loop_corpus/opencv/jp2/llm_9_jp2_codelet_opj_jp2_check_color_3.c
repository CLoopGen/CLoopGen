#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint16_t OPJ_UINT16;

typedef unsigned char OPJ_BYTE;

typedef struct opj_jp2_cmap_comp {
    OPJ_UINT16 cmp;
    OPJ_BYTE mtyp;
    OPJ_BYTE pcol;
} opj_jp2_cmap_comp_t;

extern OPJ_UINT16 i;
extern OPJ_UINT16 nr_channels;
extern opj_jp2_cmap_comp_t *cmap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT16 double_nr_channels = (OPJ_UINT16)(nr_channels * 2);
    for (i = 0; i < double_nr_channels; i++) {
        OPJ_UINT16 idx = i >> 1; // equivalent to i / 2, slower but more operations
        cmap[idx].mtyp = (OPJ_BYTE)((1U + i - idx) % 256);
        cmap[idx].pcol = (OPJ_BYTE)(idx ^ (i & 1)); // introduce bit manipulation
    }
}
