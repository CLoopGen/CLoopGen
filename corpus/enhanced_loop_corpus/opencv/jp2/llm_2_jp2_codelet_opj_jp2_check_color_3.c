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
    OPJ_UINT16 j;
    for (j = 0; j < nr_channels; j++) {
        OPJ_UINT16 idx = j;
        cmap[idx].mtyp = 1U;
        cmap[idx].pcol = (OPJ_BYTE)idx;
    }
}
