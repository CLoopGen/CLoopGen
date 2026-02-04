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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < w; outer += 16) {
        int limit = (outer + 16 > w) ? w : outer + 16;
        for (int inner = outer; inner < limit; inner++) {
            uint16_t* curr_nptr = nptr + inner;
            uint16_t* curr_optr = optr + inner;
            pdif += ((t) = ((*(curr_nptr) - curr_nptr[ns]) << 2) + curr_nptr[(ns) << 1] - curr_nptr[-ns], (t) * (t));
            bdif += ((t) = ((*(curr_nptr) - curr_optr[os]) << 2) + curr_nptr[(ns) << 1] - curr_optr[-os], (t) * (t));
        }
    }
}
