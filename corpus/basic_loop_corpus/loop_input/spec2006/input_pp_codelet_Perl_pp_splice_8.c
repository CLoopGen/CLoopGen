#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;
typedef int I32;

SV **src;
SV **dst;
I32 i;
I32 offset;

static SV *sv_array_src;
static SV *sv_array_dst;
static SV **ptr_array_src;
static SV **ptr_array_dst;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of SV objects (~262k SVs assuming 4-byte pointers + 8 bytes per SV)
    const size_t num_sv = data_size / sizeof(SV);

    // Allocate blocks of SV objects
    sv_array_src = calloc(num_sv, sizeof(SV));
    sv_array_dst = calloc(num_sv, sizeof(SV));

    // Allocate pointer arrays for src and dst
    ptr_array_src = calloc(num_sv, sizeof(SV*));
    ptr_array_dst = calloc(num_sv, sizeof(SV*));

    // Initialize source pointer array to point into sv_array_src
    for (size_t idx = 0; idx < num_sv; idx++) {
        ptr_array_src[idx] = &sv_array_src[idx];
    }

    // Set up src and dst as pointers into the arrays
    src = &ptr_array_src[num_sv - 1];  // Point to last element
    dst = &ptr_array_dst[num_sv - 1];  // Point to last element

    offset = num_sv;  // Process all elements
}