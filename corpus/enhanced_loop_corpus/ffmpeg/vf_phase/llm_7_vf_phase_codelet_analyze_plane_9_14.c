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
// Reverse loop iteration to introduce negative stride and reverse data access pattern
uint16_t *start = nptr;
for (nptr = start + w - 1, optr = optr + w - 1; nptr >= start; nptr--, optr--) {
    // Maintain same computations but in reverse order
    // This introduces a loop-carried dependence in reverse direction
    int t_val;
    t_val = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
    pdif += t_val * t_val;
    t_val = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
    tdif += t_val * t_val;
    t_val = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
    bdif += t_val * t_val;
}
}
