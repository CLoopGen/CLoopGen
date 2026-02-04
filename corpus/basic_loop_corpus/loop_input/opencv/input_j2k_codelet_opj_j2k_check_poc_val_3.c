#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

OPJ_UINT32 p_nb_resolutions = 128;
OPJ_UINT32 p_num_comps = 128;
OPJ_UINT32 p_num_layers = 16;
OPJ_UINT32 *packet_array;
OPJ_UINT32 _usr_index = 0;
OPJ_UINT32 resno;
OPJ_UINT32 compno;
OPJ_UINT32 layno;
OPJ_UINT32 step_c = 1;
OPJ_BOOL loss = 0;

void init_vars() {
    size_t total_size = (size_t)p_nb_resolutions * p_num_comps * p_num_layers;
    if (total_size == 0) {
        total_size = 1;
    }
    packet_array = (OPJ_UINT32*)calloc(total_size, sizeof(OPJ_UINT32));
    if (!packet_array) {
        exit(1);
    }
    for (size_t i = 0; i < total_size; ++i) {
        packet_array[i] = (i % 2 == 0) ? 1 : 0;
    }
    _usr_index = 0;
    step_c = 1;
    loss = 0;
}