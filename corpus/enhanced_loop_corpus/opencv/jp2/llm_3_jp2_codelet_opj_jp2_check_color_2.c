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
    // Variant 2: Indirect memory access via an index mapping array (simulated using arithmetic)
    // Simulate an indirect access pattern: traverse array in reverse order (a form of non-consecutive access)
    OPJ_UINT16 *indices = (OPJ_UINT16*)alloca(n * sizeof(OPJ_UINT16));
    for (OPJ_UINT16 j = 0; j < n; ++j) {
        indices[j] = n - 1 - j; // Reverse mapping: access from end to start
    }
    for (i = 0; i < n; ++i) {
        OPJ_UINT16 mapped_index = indices[i];
        if ((OPJ_UINT32)info[mapped_index].cn == (nr_channels - 1U)) {
            i = mapped_index; // Preserve the actual channel index upon break
            break;
        }
    }
}
