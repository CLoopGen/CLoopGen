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
    uint16_t *n_temp = nptr;
    uint16_t *o_temp = optr;
    uint16_t *rend_local = n_temp + w;
    int64_t pdif_local = 0;
    int64_t tdif_local = 0;
    int t_local;

    for (; n_temp < rend_local; n_temp++, o_temp++) {
        int ns_val = ns;
        int os_val = os;
        uint16_t curr_n = *n_temp;
        uint16_t neighbor_ns = n_temp[ns_val];
        uint16_t neighbor_2ns = n_temp[ns_val << 1];
        uint16_t neighbor_neg_ns = n_temp[-ns_val];

        t_local = ((curr_n - neighbor_ns) << 2) + neighbor_2ns - neighbor_neg_ns;
        pdif_local += t_local * t_local;

        uint16_t curr_o = *o_temp;
        uint16_t o_2os = o_temp[os_val << 1];
        t_local = ((curr_o - neighbor_ns) << 2) + o_2os - neighbor_neg_ns;
        tdif_local += t_local * t_local;
    }

    pdif += pdif_local;
    tdif += tdif_local;
}
