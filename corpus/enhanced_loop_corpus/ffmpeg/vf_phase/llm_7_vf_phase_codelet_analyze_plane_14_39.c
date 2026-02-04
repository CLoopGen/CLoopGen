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
int64_t local_pdif = 0, local_bdif = 0, local_tdif = 0;
uint16_t *local_nptr = nptr;
uint16_t *local_optr = optr;

for (rend = local_nptr + w; local_nptr < rend; local_nptr++, local_optr++) {
    int64_t t1 = (*(local_nptr) - local_nptr[ns]) << 2;
    int64_t t2 = (*(local_optr) - local_nptr[ns]) << 2;
    int64_t t3 = (*(local_nptr) - local_optr[os]) << 2;

    t1 += local_nptr[(ns) << 1] - local_nptr[-ns];
    t2 += local_optr[(os) << 1] - local_nptr[-ns];
    t3 += local_nptr[(ns) << 1] - local_optr[-os];

    local_pdif += t1 * t1;
    local_bdif += t3 * t3;
    local_tdif += t2 * t2;
}

pdif += local_pdif;
bdif += local_bdif;
tdif += local_tdif;
nptr = local_nptr;
optr = local_optr;
}
