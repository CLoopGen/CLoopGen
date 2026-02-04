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
    if (w > 0) {
        rend = nptr + w;
        for (int stride = 4; stride <= 4; stride *= 2) {
            for (int j = 0; j < stride; j++) {
                uint16_t *nptr_temp = nptr + j;
                uint16_t *optr_temp = optr + j;
                for (; nptr_temp < rend; nptr_temp += stride, optr_temp += stride) {
                    pdif += ((t) = ((*(nptr_temp) - (nptr_temp)[ns]) << 2) + (nptr_temp)[(ns) << 1] - (nptr_temp)[-(ns)], (t) * (t));
                    tdif += ((t) = ((*(nptr_temp) - (optr_temp)[os]) << 2) + (nptr_temp)[(ns) << 1] - (optr_temp)[-(os)], (t) * (t));
                    bdif += ((t) = ((*(optr_temp) - (nptr_temp)[ns]) << 2) + (optr_temp)[(os) << 1] - (nptr_temp)[-(ns)], (t) * (t));
                }
            }
            break; // Ensures single iteration of outer loop, simulating controlled depth increase
        }
    }
}
