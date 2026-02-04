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
    int64_t temp_n_ns = (nptr)[ns];
    int64_t temp_n_2ns = (nptr)[(ns) << 1];
    int64_t temp_n_mns = (nptr)[-(ns)];
    int64_t temp_o_os = (optr)[os];
    int64_t temp_o_2os = (optr)[(os) << 1];
    int64_t temp_o_mos = (optr)[-(os)];

    t = ((*(nptr) - temp_n_ns) << 2) + temp_n_2ns - temp_n_mns;
    pdif += t * t;

    t = ((*(nptr) - temp_o_os) << 2) + temp_n_2ns - temp_o_mos;
    bdif += t * t;

    t = ((*(optr) - temp_n_ns) << 2) + temp_o_2os - temp_n_mns;
    tdif += t * t;
}
}
