#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t bdif;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride for spatial skipping (stride = 2)
    int64_t local_pdif = 0, local_bdif = 0, local_tdif = 0;
    int i;
    int stride = 2;
    int effective_width = w / stride * stride; // Ensure we don't go out of bounds

    for (i = 0; i < effective_width; i += stride) {
        uint16_t *curr_n_ptr = nptr + i;
        uint16_t *curr_o_ptr = optr + i;

        int t1 = (((*curr_n_ptr) - curr_n_ptr[ns]) << 2) + curr_n_ptr[(ns) << 1] - curr_n_ptr[-ns];
        local_pdif += t1 * t1;

        int t2 = (((*curr_n_ptr) - curr_o_ptr[os]) << 2) + curr_n_ptr[(ns) << 1] - curr_o_ptr[-os];
        local_bdif += t2 * t2;

        int t3 = (((*curr_o_ptr) - curr_n_ptr[ns]) << 2) + curr_o_ptr[(os) << 1] - curr_n_ptr[-ns];
        local_tdif += t3 * t3;
    }

    // Handle remaining elements if w is not divisible by stride
    for (; i < w; i++) {
        uint16_t *curr_n_ptr = nptr + i;
        uint16_t *curr_o_ptr = optr + i;

        int t1 = (((*curr_n_ptr) - curr_n_ptr[ns]) << 2) + curr_n_ptr[(ns) << 1] - curr_n_ptr[-ns];
        local_pdif += t1 * t1;

        int t2 = (((*curr_n_ptr) - curr_o_ptr[os]) << 2) + curr_n_ptr[(ns) << 1] - curr_o_ptr[-os];
        local_bdif += t2 * t2;

        int t3 = (((*curr_o_ptr) - curr_n_ptr[ns]) << 2) + curr_o_ptr[(os) << 1] - curr_n_ptr[-ns];
        local_tdif += t3 * t3;
    }

    pdif += local_pdif;
    bdif += local_bdif;
    tdif += local_tdif;
}
