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
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increasing step size (every 4th element)
    const int stride = 4;
    uint16_t *base_n = nptr;
    uint16_t *base_o = optr;
    int count = 0;
    for (; count < w; count += stride) {
        uint16_t *curr_n = base_n + count;
        uint16_t *curr_o = base_o + count;
        if (curr_n >= base_n + w) break;

        t = ((*curr_n - curr_o[os]) << 2) + curr_n[(ns) << 1] - curr_o[-os];
        bdif += t * t;

        t = ((*curr_o - curr_n[ns]) << 2) + curr_o[(os) << 1] - curr_n[-ns];
        tdif += t * t;
    }
}
