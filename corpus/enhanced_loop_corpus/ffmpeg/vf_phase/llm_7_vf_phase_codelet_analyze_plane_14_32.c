#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse iteration order to change data access pattern and introduce anti-dependence (WAR) elimination
    uint16_t *start = nptr;
    nptr += w - 1;
    optr += w - 1;

    int64_t temp_pdif = 0;
    int64_t temp_tdif = 0;

    for (rend = start - 1; nptr > rend; nptr--, optr--) {
        int t_val;
        // Reorder computation slightly: use symmetric indexing with fixed offset arithmetic
        // Create artificial temporary reuse to modify data dependency graph
        t_val = ((*nptr - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        temp_pdif += t_val * t_val;

        t_val = ((*nptr - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        temp_tdif += t_val * t_val;
    }

    // Accumulate into shared totals (still correct final result)
    pdif += temp_pdif;
    tdif += temp_tdif;
}
