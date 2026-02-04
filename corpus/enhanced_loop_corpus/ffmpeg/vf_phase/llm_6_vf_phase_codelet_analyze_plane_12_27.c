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
for (rend = nptr + w; nptr < rend; nptr++ , optr++) {
    int64_t temp_n_ns = *(nptr) - (nptr)[ns];
    int64_t temp_n_2ns = (nptr)[(ns) << 1];
    int64_t temp_n_mns = (nptr)[-(ns)];
    t = (temp_n_ns << 2) + temp_n_2ns - temp_n_mns;
    pdif += t * t;

    int64_t temp_o_os = *(optr) - (optr)[os];
    int64_t temp_n_2ns_again = (nptr)[(ns) << 1]; // Re-reading to preserve value
    int64_t temp_o_mos = (optr)[-(os)];
    t = ((*(nptr) - temp_o_os) << 2) + temp_n_2ns_again - temp_o_mos;
    bdif += t * t;
}
}
