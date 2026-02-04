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
    uint8_t *nptr_local = nptr;
    uint8_t *optr_local = optr;
    int pdif_local = pdif;
    int tdif_local = tdif;
    int bdif_local = bdif;
    uint8_t *rend_local = nptr_local + w;

    for (; nptr_local < rend_local; nptr_local++, optr_local++) {
        int t_n = (nptr_local[0] - nptr_local[ns]) << 2;
        int t_n_forward = nptr_local[(ns) << 1];
        int t_n_backward = nptr_local[-ns];
        int diff_n = t_n + t_n_forward - t_n_backward;
        pdif_local += diff_n * diff_n;

        int t_no = (nptr_local[0] - optr_local[os]) << 2;
        int t_n_forward2 = nptr_local[(ns) << 1];
        int t_o_backward = optr_local[-os];
        int diff_no = t_no + t_n_forward2 - t_o_backward;
        tdif_local += diff_no * diff_no;

        int t_on = (optr_local[0] - nptr_local[ns]) << 2;
        int t_o_forward = optr_local[(os) << 1];
        int t_n_backward2 = nptr_local[-ns];
        int diff_on = t_on + t_o_forward - t_n_backward2;
        bdif_local += diff_on * diff_on;
    }

    pdif = pdif_local;
    tdif = tdif_local;
    bdif = bdif_local;
    nptr = nptr_local;
    optr = optr_local;
}
