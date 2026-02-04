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
    uint16_t *nrend = nptr + w;
    int64_t local_pdif = 0;
    int64_t local_tdif = 0;
    uint16_t *local_nptr = nptr;
    uint16_t *local_optr = optr;

    for (; local_nptr < nrend; local_nptr++, local_optr++) {
        int t_n = (*(local_nptr) - local_nptr[ns]) << 2;
        t_n += local_nptr[(ns) << 1] - local_nptr[-ns];
        local_pdif += t_n * t_n;

        int t_o = (*(local_optr) - local_nptr[ns]) << 2;
        t_o += local_optr[(os) << 1] - local_nptr[-ns];
        local_tdif += t_o * t_o;
    }

    pdif += local_pdif;
    tdif += local_tdif;
    nptr = local_nptr;
    optr = local_optr;
}
