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
        uint16_t* curr_n = nptr + i;
        uint16_t* curr_o = optr + i;
        pdif += ((t) = ((curr_n[0] - curr_n[ns]) << 2) + curr_n[(ns) << 1] - curr_n[-ns], (t) * (t));
        tdif += ((t) = ((curr_o[0] - curr_n[ns]) << 2) + curr_o[(os) << 1] - curr_n[-ns], (t) * (t));
    }
}
