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



void loop() {
    // Variant 2: Consecutive Forward Access with Local Array Indices
    uint16_t *nbase = nptr;
    uint16_t *obase = optr;
    int i;
    for (i = 0; i < w; i++) {
        uint16_t n_val = nbase[i];
        uint16_t n_ns = (i + ns < w) ? nbase[i + ns] : nbase[w - 1];
        uint16_t n_2ns = (i + (ns << 1) < w) ? nbase[i + (ns << 1)] : nbase[w - 1];
        uint16_t n_neg_ns = (i >= ns) ? nbase[i - ns] : nbase[0];
        uint16_t o_val = obase[i];
        uint16_t o_2os = (i + (os << 1) < w) ? obase[i + (os << 1)] : obase[w - 1];

        pdif += ((t) = ((n_val - n_ns) << 2) + n_2ns - n_neg_ns, (t) * (t));
        tdif += ((t) = ((o_val - n_ns) << 2) + o_2os - n_neg_ns, (t) * (t));
    }
}
