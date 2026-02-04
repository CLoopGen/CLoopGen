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
    // Variant 1: Consecutive memory access with manual stride simulation using index arithmetic
    int64_t local_pdif = 0, local_bdif = 0, local_tdif = 0;
    int i;
    for (i = 0; i < w; i++) {
        uint16_t curr_n = nptr[i];
        uint16_t next_n_ns = nptr[i + ns];
        uint16_t next_n_2ns = nptr[i + (ns << 1)];
        uint16_t prev_n_ns = nptr[i - ns];
        uint16_t curr_o = optr[i];
        uint16_t next_o_os = optr[i + os];
        uint16_t next_o_2os = optr[i + (os << 1)];
        uint16_t prev_o_os = optr[i - os];

        int t1 = ((curr_n - next_n_ns) << 2) + next_n_2ns - prev_n_ns;
        local_pdif += t1 * t1;

        int t2 = ((curr_n - next_o_os) << 2) + next_n_2ns - prev_o_os;
        local_bdif += t2 * t2;

        int t3 = ((curr_o - next_n_ns) << 2) + next_o_2os - prev_n_ns;
        local_tdif += t3 * t3;
    }
    pdif += local_pdif;
    bdif += local_bdif;
    tdif += local_tdif;
}
