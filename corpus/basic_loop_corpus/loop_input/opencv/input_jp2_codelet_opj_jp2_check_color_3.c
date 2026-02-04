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

OPJ_UINT16 i;
OPJ_UINT16 nr_channels;
opj_jp2_cmap_comp_t *cmap;

void init_vars() {
    nr_channels = 65536; // Approximate size to run loop for ~0.01 seconds
    cmap = (opj_jp2_cmap_comp_t*)calloc(nr_channels, sizeof(opj_jp2_cmap_comp_t));
    if (!cmap) {
        exit(1);
    }
    i = 0;
}