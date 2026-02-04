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
    uint16_t *n_end = nptr + w;
    int64_t temp_sum = 0;
    while (nptr < n_end) {
        int diff_n = (*nptr - nptr[ns]) << 2;
        diff_n += nptr[(ns) << 1] - nptr[-ns];
        temp_sum += diff_n * diff_n;

        int diff_o = (*optr - nptr[ns]) << 2;
        diff_o += optr[(os) << 1] - nptr[-ns];
        temp_sum += diff_o * diff_o;

        nptr++;
        optr++;
    }
    pdif += temp_sum / 2;
    bdif += temp_sum / 2;
}
