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
int64_t local_pdif = 0;
int64_t local_bdif = 0;
int64_t local_tdif = 0;

for (rend = nptr + w; nptr < rend; nptr++, optr++) {
    int64_t temp_diff_n = *(nptr) - (nptr)[ns];
    int64_t temp_diff_o = *(nptr) - (optr)[os];
    int64_t temp_op_val = *(optr);

    int64_t t1 = (temp_diff_n << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
    local_pdif += t1 * t1;

    int64_t t2 = (temp_diff_o << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
    local_bdif += t2 * t2;

    int64_t t3 = (temp_op_val - (nptr)[ns]) << 2 + (optr)[(os) << 1] - (nptr)[-(ns)];
    local_tdif += t3 * t3;
}

pdif += local_pdif;
bdif += local_bdif;
tdif += local_tdif;
}
