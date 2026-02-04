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
    uint16_t *n_temp = nptr;
    uint16_t *o_temp = optr;
    int64_t pdif_local = 0;
    int64_t bdif_local = 0;
    for (rend = n_temp + w; n_temp < rend; n_temp++, o_temp++) {
        int t1 = ((*(n_temp) - n_temp[ns]) << 2) + n_temp[(ns) << 1] - n_temp[-(ns)];
        int t2 = ((*(o_temp) - n_temp[ns]) << 2) + o_temp[(os) << 1] - n_temp[-(ns)];
        pdif_local += t1 * t1;
        bdif_local += t2 * t2;
    }
    pdif += pdif_local;
    bdif += bdif_local;
}
