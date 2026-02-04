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
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int64_t temp_n, temp_o;
        pdif += (temp_n = ((*(nptr) - nptr[ns]) << 2) + nptr[ns << 1] - nptr[-ns], temp_n * temp_n);
        tdif += (temp_o = ((*(optr) - nptr[ns]) << 2) + optr[os << 1] - nptr[-ns], temp_o * temp_o);
    }
}
