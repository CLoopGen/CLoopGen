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
    // Variant 2: Strided memory access with fixed step > 1 to simulate sparse traversal
    const int stride = 4;  // Access every 4th element
    uint16_t *n_end = nptr + w;
    uint16_t *o_current = optr;

    for (int i = 0; nptr + i < n_end; i += stride) {
        uint16_t *curr_n = nptr + i;
        uint16_t *curr_o = o_current + i;

        int64_t temp_n = ((curr_n[0] - curr_n[ns]) << 2) + curr_n[ns << 1] - curr_n[-ns];
        pdif += temp_n * temp_n;

        int64_t temp_o = ((curr_o[0] - curr_n[ns]) << 2) + curr_o[os << 1] - curr_n[-ns];
        tdif += temp_o * temp_o;
    }
}
