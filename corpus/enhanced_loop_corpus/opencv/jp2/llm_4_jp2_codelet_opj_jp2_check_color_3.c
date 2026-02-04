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
for (i = 0; i < nr_channels; i++) {
    if (i % 2 == 0) {
        cmap[i].mtyp = 1U;
    } else {
        cmap[i].mtyp = 0U;
    }
    cmap[i].pcol = (OPJ_BYTE)i;
}
}
