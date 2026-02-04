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
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < w; i += 2) {
        uint16_t *n1 = nptr + i;
        uint16_t *o1 = optr + i;
        if (n1 + 1 < nptr + w) {
            tdif += ((t) = ((n1[0] - o1[os]) << 2) + n1[(ns) << 1] - o1[-os], (t) * (t));
            bdif += ((t) = ((o1[0] - n1[ns]) << 2) + o1[(os) << 1] - n1[-ns], (t) * (t));
            tdif += ((t) = ((n1[1] - o1[os+1]) << 2) + (n1+1)[(ns) << 1] - (o1+1)[-os], (t) * (t));
            bdif += ((t) = ((o1[1] - (n1+1)[ns]) << 2) + (o1+1)[(os) << 1] - (n1+1)[-ns], (t) * (t));
        } else {
            tdif += ((t) = ((*n1 - o1[os]) << 2) + n1[(ns) << 1] - o1[-os], (t) * (t));
            bdif += ((t) = ((*o1 - n1[ns]) << 2) + o1[(os) << 1] - n1[-ns], (t) * (t));
        }
    }
}
