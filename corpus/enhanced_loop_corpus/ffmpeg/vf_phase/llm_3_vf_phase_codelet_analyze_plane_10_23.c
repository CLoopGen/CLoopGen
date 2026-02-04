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
    // Variant 2: Strided memory access – process every 4th element first, then the rest
    // This changes access pattern to increase stride, simulating non-contiguous access behavior
    const int stride = 4;
    for (int phase = 0; phase < stride; phase++) {
        uint16_t *local_nptr = nptr + phase;
        uint16_t *local_optr = optr + phase;
        rend = nptr + w;

        for (; local_nptr < rend; local_nptr += stride, local_optr += stride) {
            int t_val;

            pdif += (t_val = (((*local_nptr) - local_nptr[ns]) << 2) + local_nptr[(ns) << 1] - local_nptr[-ns], (int64_t)t_val * t_val);
            bdif += (t_val = (((*local_nptr) - local_optr[os]) << 2) + local_nptr[(ns) << 1] - local_optr[-os], (int64_t)t_val * t_val);
            tdif += (t_val = (((*local_optr) - local_nptr[ns]) << 2) + local_optr[(os) << 1] - local_nptr[-ns], (int64_t)t_val * t_val);
        }
    }
}
