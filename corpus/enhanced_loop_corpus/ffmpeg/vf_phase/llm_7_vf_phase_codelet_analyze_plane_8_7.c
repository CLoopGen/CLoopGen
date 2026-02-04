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
int local_pdif = 0, local_bdif = 0, local_tdif = 0;
for (rend = nptr + w; nptr < rend; nptr++, optr++) {
    int diff_n = (*(nptr) - nptr[ns]);
    int diff_o = (*(optr) - optr[os]);

    int t1 = (diff_n << 2) + nptr[(ns) << 1] - nptr[-ns];
    int t2 = (diff_o << 2) + nptr[(ns) << 1] - optr[-os];
    int t3 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];

    local_pdif += t1 * t1;
    local_bdif += t2 * t2;
    local_tdif += t3 * t3;
}

pdif += local_pdif;
bdif += local_bdif;
tdif += local_tdif;
}
