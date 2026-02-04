#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef int OPJ_BOOL;

extern OPJ_UINT32 p_nb_resolutions;
extern OPJ_UINT32 p_num_comps;
extern OPJ_UINT32 p_num_layers;
extern OPJ_UINT32 *packet_array;
extern OPJ_UINT32 _usr_index;
extern OPJ_UINT32 resno;
extern OPJ_UINT32 compno;
extern OPJ_UINT32 layno;
extern OPJ_UINT32 step_c;
extern OPJ_BOOL loss;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    OPJ_UINT32 idx = index;
    OPJ_UINT32 stride = step_c;
    OPJ_UINT32 total_comps = p_num_comps;
    OPJ_UINT32 total_res = p_nb_resolutions;
    OPJ_UINT32 total_layers = p_num_layers;

    for (OPJ_UINT32 l = 0; l < total_layers * total_res * total_comps; ++l) {
        OPJ_UINT32 linear_compno = l % total_comps;
        OPJ_UINT32 linear_resno = (l / total_comps) % total_res;
        OPJ_UINT32 linear_layno = l / (total_comps * total_res);

        OPJ_UINT32 base_offset = idx + (linear_layno * total_res * total_comps + linear_resno * total_comps + linear_compno) * stride;
        loss |= (packet_array[base_offset] != 1);
    }

    index = idx + (total_layers * total_res * total_comps) * stride;
}
