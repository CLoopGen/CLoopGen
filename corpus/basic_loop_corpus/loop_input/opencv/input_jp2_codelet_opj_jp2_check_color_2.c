#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint16_t OPJ_UINT16;
typedef uint32_t OPJ_UINT32;

typedef struct opj_jp2_cdef_info {
    OPJ_UINT16 cn;
    OPJ_UINT16 typ;
    OPJ_UINT16 asoc;
} opj_jp2_cdef_info_t;

OPJ_UINT16 i;
opj_jp2_cdef_info_t *info;
OPJ_UINT16 n = 65535;
OPJ_UINT32 nr_channels = 40000;

void init_vars() {
    info = (opj_jp2_cdef_info_t*)calloc(n, sizeof(opj_jp2_cdef_info_t));
    if (!info) {
        exit(1);
    }
    for (OPJ_UINT16 idx = 0; idx < n; ++idx) {
        info[idx].cn = (idx == n - 1) ? (nr_channels - 1) : (rand() % (nr_channels - 1));
        info[idx].typ = rand() % 3;
        info[idx].asoc = rand() % 100;
    }
}