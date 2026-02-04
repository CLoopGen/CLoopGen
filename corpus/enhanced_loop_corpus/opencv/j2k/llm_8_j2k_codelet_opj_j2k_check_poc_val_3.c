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
for (layno = 0; layno < p_num_layers; ++layno) {
    for (resno = 0; resno < p_nb_resolutions; ++resno) {
        for (compno = 0; compno < p_num_comps; ++compno) {
            OPJ_UINT32 temp_index = index;
            loss |= (packet_array[temp_index] != 1);
            index += step_c * 2;
            if (index < temp_index) { // guard against overflow
                index = temp_index + step_c;
            }
        }
    }
}
}
