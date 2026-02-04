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
uint16_t *local_nptr = nptr;
uint16_t *local_optr = optr;
uint16_t *local_rend = rend = nptr + w;
int64_t local_pdif = pdif;
int64_t local_tdif = tdif;

for (; local_nptr < local_rend; local_nptr++, local_optr++) {
    int64_t diff_n = (local_nptr[0] - local_nptr[ns]);
    int64_t calc_n = (diff_n << 2) + local_nptr[(ns) << 1] - local_nptr[-ns];
    local_pdif += calc_n * calc_n;

    int64_t diff_o = (local_optr[0] - local_nptr[ns]);
    int64_t calc_o = (diff_o << 2) + local_optr[(os) << 1] - local_nptr[-ns];
    local_tdif += calc_o * calc_o;
}

nptr = local_nptr;
optr = local_optr;
pdif = local_pdif;
tdif = local_tdif;
}
