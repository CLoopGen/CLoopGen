#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int inner = 0;
        for (int i = 0; i < 2; i++) {
            int temp_nptr_shift = (i == 0) ? ns : -ns;
            pdif += ((t) = ((*(nptr) - nptr[temp_nptr_shift]) << 2) + nptr[(ns) << 1] - nptr[-(ns)], (t) * (t));
            if (i == 0) {
                bdif += ((t) = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)], (t) * (t));
            }
        }
    }
}
