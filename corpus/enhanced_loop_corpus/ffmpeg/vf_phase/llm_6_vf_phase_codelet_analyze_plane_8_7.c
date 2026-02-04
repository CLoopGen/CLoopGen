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
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + w; nptr < rend; nptr++ , optr++) {
    int t_nptr_ns = *(nptr) - nptr[ns];
    int t_optr_os = *(optr) - optr[os];
    int t_optr_ns = *(optr) - nptr[ns];

    pdif += ((t) = (t_nptr_ns << 2) + nptr[(ns) << 1] - nptr[-ns], t * t);
    bdif += ((t) = (t_optr_os << 2) + nptr[(ns) << 1] - optr[-os], t * t);
    tdif += ((t) = (t_optr_ns << 2) + optr[(os) << 1] - nptr[-ns], t * t);
}
}
