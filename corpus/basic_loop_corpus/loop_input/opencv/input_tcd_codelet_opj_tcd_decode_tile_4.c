#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

OPJ_UINT32 numcomps_to_decode = 65536;
OPJ_UINT32 *comps_indices;
OPJ_UINT32 compno;
OPJ_BOOL *used_component;

void init_vars() {
    // Allocate and initialize comps_indices: map each component index to a valid used_component index
    comps_indices = (OPJ_UINT32*)malloc(numcomps_to_decode * sizeof(OPJ_UINT32));
    
    // Allocate used_component with size large enough to avoid out-of-bounds access
    // Assume max value in comps_indices is less than 131072
    OPJ_UINT32 max_index = 131072;
    used_component = (OPJ_BOOL*)calloc(max_index, sizeof(OPJ_BOOL));

    // Initialize comps_indices: map compno to a wrapped index within [0, max_index)
    for (OPJ_UINT32 i = 0; i < numcomps_to_decode; ++i) {
        comps_indices[i] = i % max_index;
    }
}