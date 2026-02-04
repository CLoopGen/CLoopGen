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
    for (int i = 0; i < w; i++) {
        uint16_t* curr_nptr = nptr + i;
        uint16_t* curr_optr = optr + i;
        int64_t t_val;

        t_val = ((*(curr_nptr) - curr_nptr[ns]) << 2) + curr_nptr[(ns) << 1] - curr_nptr[-ns];
        pdif += t_val * t_val;

        t_val = ((*(curr_optr) - curr_nptr[ns]) << 2) + curr_optr[(os) << 1] - curr_nptr[-ns];
        tdif += t_val * t_val;
    }
}
