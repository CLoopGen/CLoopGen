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
    // Variant 1: Consecutive memory access with reordered computation
    // Arrays are accessed consecutively by precomputing base offsets and using index arithmetic
    uint16_t *nbase = nptr;
    uint16_t *obase = optr;
    int i;
    for (i = 0; i < w; i++) {
        uint16_t n_val = nbase[i];
        uint16_t o_val = obase[i];
        uint16_t n_next = nbase[i + (ns << 1)];
        uint16_t o_next = obase[i + (os << 1)];
        uint16_t n_prev = nbase[i - ns];
        uint16_t o_prev = obase[i - os];

        int t1 = ((n_val - o_val) << 2) + n_next - o_prev;
        tdif += t1 * t1;

        int t2 = ((o_val - n_val) << 2) + o_next - n_prev;
        bdif += t2 * t2;
    }
}
