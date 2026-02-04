#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint16_t OPJ_UINT16;

typedef struct opj_jp2_cdef_info {
    OPJ_UINT16 cn;
    OPJ_UINT16 typ;
    OPJ_UINT16 asoc;
} opj_jp2_cdef_info_t;

typedef uint32_t OPJ_UINT32;

extern OPJ_UINT16 i;
extern opj_jp2_cdef_info_t *info;
extern OPJ_UINT16 n;
extern OPJ_UINT32 nr_channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT16 local_cn = 0;
    for (i = 0; i < n; ++i) {
        local_cn = info[i].cn; // Remove direct dependency on previous iterations by using local copy
        if ((OPJ_UINT32)local_cn == (nr_channels - 1U)) {
            i++; // Modify loop index with WAW-like effect (write after write on i)
            break;
        }
    }
}
