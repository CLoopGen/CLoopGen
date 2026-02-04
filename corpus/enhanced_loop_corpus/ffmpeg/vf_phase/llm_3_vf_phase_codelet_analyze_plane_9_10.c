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
    // Variant 2: Strided Memory Access with increased stride (stride = 4)
    const int stride = 4;
    rend = nptr + w;
    uint16_t *nbase = nptr;
    uint16_t *obase = optr;

    for (int i = 0; i <= w - stride; i += stride) {
        int64_t temp_pdif = 0, temp_bdif = 0;

        // Accumulate differences using strided access
        for (int j = 0; j < stride; j++) {
            uint16_t *nptr_j = nbase + i + j;
            uint16_t *optr_j = obase + i + j;

            int64_t t_val = ((nptr_j[0] - nptr_j[ns]) << 2) + nptr_j[(ns) << 1] - nptr_j[-ns];
            temp_pdif += t_val * t_val;

            t_val = ((optr_j[0] - nptr_j[ns]) << 2) + optr_j[(os) << 1] - nptr_j[-ns];
            temp_bdif += t_val * t_val;
        }

        pdif += temp_pdif;
        bdif += temp_bdif;
    }

    // Handle trailing elements
    for (; nbase + w - nptr >= 1; nptr++, optr++) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    }
}
