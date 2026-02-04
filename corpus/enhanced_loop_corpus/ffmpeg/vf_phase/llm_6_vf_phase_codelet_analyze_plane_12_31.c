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
    int t1, t2, t3;
    uint16_t val_nptr = *nptr;
    uint16_t val_nptr_ns = nptr[ns];
    uint16_t val_nptr_2ns = nptr[(ns) << 1];
    uint16_t val_nptr_mns = nptr[-ns];
    uint16_t val_optr = *optr;
    uint16_t val_optr_os = optr[os];
    uint16_t val_optr_2os = optr[(os) << 1];
    uint16_t val_optr_mos = optr[-os];

    t1 = ((val_nptr - val_nptr_ns) << 2) + val_nptr_2ns - val_nptr_mns;
    pdif += t1 * t1;

    t2 = ((val_nptr - val_optr_os) << 2) + val_nptr_2ns - val_optr_mos;
    bdif += t2 * t2;

    t3 = ((val_optr - val_nptr_ns) << 2) + val_optr_2os - val_nptr_mns;
    tdif += t3 * t3;
}
}
