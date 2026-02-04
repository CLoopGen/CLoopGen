#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant introduces artificial loop-carried dependency via an accumulator to change data flow
    OPJ_INT32 acc = 0;  // Loop-carried dependency introduced (RAW dependency across iterations)
    for (; i < win_l_x1; i++) {
        for (off = 0; off < 4; off++) {
            OPJ_INT32 neighbor_val, current_val;

            // Modify indexing pattern slightly: use accumulated value to perturb access (WAR-like effect simulated)
            OPJ_UINT32 adjusted_off = (off + acc) & 3;  // Wrap-around using accumulator

            // Load with modified offset dependency on prior iteration's result
            neighbor_val = (i - 1) < 0 ? 
                a[(1 + (OPJ_UINT32)(0) * 2) * 4 + adjusted_off] : 
                ((i - 1) >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + adjusted_off] : 
                 a[(1 + (OPJ_UINT32)(i - 1) * 2) * 4 + adjusted_off]);

            current_val = i < 0 ? 
                a[(1 + (OPJ_UINT32)(0) * 2) * 4 + adjusted_off] : 
                (i >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + adjusted_off] : 
                 a[(1 + (OPJ_UINT32)(i) * 2) * 4 + adjusted_off]);

            OPJ_INT32 avg = (neighbor_val + current_val + 2) >> 2;

            // Update memory and feed into accumulator — creates WAW and RAW loop-carried dependency
            a[(OPJ_UINT32)(i) * 2 * 4 + off] -= avg;
            acc += avg;  // Accumulator carries dependency to next iteration
            acc &= 0xFF; // Bound accumulator to prevent overflow
        }
    }
}
