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
extern int tdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int t_val;
        tdif += (t_val = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], t_val * t_val);
        bdif += (t_val = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns], t_val * t_val);
    }
}
