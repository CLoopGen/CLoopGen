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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + w; nptr < rend; nptr++ , optr++) {
    int64_t t_nptr_ns = *(nptr) - (nptr)[ns];
    int64_t t_optr_os = *(nptr) - (optr)[os];
    int64_t t_optr_val = *(optr);
    
    pdif += ((t) = (t_nptr_ns << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
    bdif += ((t) = (t_optr_os << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
    tdif += ((t) = (t_optr_val - (nptr)[ns]) << 2 + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
}
}
