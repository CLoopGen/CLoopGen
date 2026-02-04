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
    for (int j = 0; j < 1; j++) {
        for (rend = nptr + w; nptr < rend; nptr++, optr++) {
            int64_t diff_n = (*(nptr) - nptr[ns]) << 2;
            int64_t term_n = diff_n + nptr[(ns) << 1] - nptr[-ns];
            pdif += term_n * term_n;

            int64_t diff_o = (*(nptr) - optr[os]) << 2;
            int64_t term_o = diff_o + nptr[(ns) << 1] - optr[-os];
            tdif += term_o * term_o;
        }
    }
}
