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
    int i;
    for (i = 0; i < w; i++) {
        uint16_t *curr_n = nptr + i;
        uint16_t *curr_o = optr + i;

        int64_t term_n = ((*(curr_n) - curr_n[ns]) << 2) + curr_n[(ns) << 1] - curr_n[-ns];
        pdif += term_n * term_n;

        int64_t term_o = ((*(curr_n) - curr_o[os]) << 2) + curr_n[(ns) << 1] - curr_o[-os];
        bdif += term_o * term_o;
    }
}
