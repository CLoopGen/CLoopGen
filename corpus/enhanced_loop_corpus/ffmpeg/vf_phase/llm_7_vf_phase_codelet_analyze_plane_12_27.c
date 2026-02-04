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
int64_t local_pdif = 0;
int64_t local_bdif = 0;
uint16_t *local_nptr = nptr;
uint16_t *local_optr = optr;

for (rend = local_nptr + w; local_nptr < rend; local_nptr++, local_optr++) {
    int64_t diff_n = (local_nptr[0] - local_nptr[ns]) << 2;
    diff_n += local_nptr[ns << 1] - local_nptr[-ns];
    local_pdif += diff_n * diff_n;

    int64_t diff_b = (local_nptr[0] - local_optr[os]) << 2;
    diff_b += local_nptr[ns << 1] - local_optr[-os];
    local_bdif += diff_b * diff_b;
}

pdif += local_pdif;
bdif += local_bdif;
nptr = local_nptr;
optr = local_optr;
}
