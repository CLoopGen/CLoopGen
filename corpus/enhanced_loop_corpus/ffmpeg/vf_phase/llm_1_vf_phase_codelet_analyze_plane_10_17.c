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
    for (int i = 0; i < w; i += 2) {
        uint16_t *n1 = nptr + i;
        uint16_t *o1 = optr + i;
        if (n1 + 1 < rend) {
            // First element in pair
            int64_t t1_n = ((*n1 - n1[ns]) << 2) + n1[ns << 1] - n1[-ns];
            pdif += t1_n * t1_n;
            int64_t t1_o = ((*o1 - n1[ns]) << 2) + o1[os << 1] - n1[-ns];
            tdif += t1_o * t1_o;

            // Second element in pair
            uint16_t *n2 = n1 + 1;
            uint16_t *o2 = o1 + 1;
            int64_t t2_n = ((*n2 - n2[ns]) << 2) + n2[ns << 1] - n2[-ns];
            pdif += t2_n * t2_n;
            int64_t t2_o = ((*o2 - n2[ns]) << 2) + o2[os << 1] - n2[-ns];
            tdif += t2_o * t2_o;
        } else if (n1 < rend) {
            int64_t t_n = ((*n1 - n1[ns]) << 2) + n1[ns << 1] - n1[-ns];
            pdif += t_n * t_n;
            int64_t t_o = ((*o1 - n1[ns]) << 2) + o1[os << 1] - n1[-ns];
            tdif += t_o * t_o;
        }
    }
}
