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



void loop() {
    // Variant 2: Strided memory access with increasing step size (stride = 4)
    const int stride = 4;
    uint16_t *n_base = nptr;
    uint16_t *o_base = optr;
    int count = w / stride;

    for (int i = 0; i < count; ++i) {
        uint16_t *nptr_temp = n_base + i * stride;
        uint16_t *optr_temp = o_base + i * stride;

        // Use only the first and last element in each block to simulate strided pattern
        // First in block
        t = ((*nptr_temp - optr_temp[os]) << 2) + nptr_temp[ns << 1] - optr_temp[-os];
        bdif += t * t;
        t = ((*optr_temp - nptr_temp[ns]) << 2) + optr_temp[os << 1] - nptr_temp[-ns];
        tdif += t * t;

        // Last in block (if within bounds)
        uint16_t *n_last = nptr_temp + stride - 1;
        uint16_t *o_last = optr_temp + stride - 1;
        t = ((*n_last - o_last[os]) << 2) + n_last[ns << 1] - o_last[-os];
        bdif += t * t;
        t = ((*o_last - n_last[ns]) << 2) + o_last[os << 1] - n_last[-ns];
        tdif += t * t;
    }

    // Final cleanup: process any leftover elements not aligned to stride*2
    for (int i = count * stride * 2; i < w; ++i) {
        t = ((n_base[i] - o_base[i + os]) << 2) + n_base[i + (ns << 1)] - o_base[i - os];
        bdif += t * t;
        t = ((o_base[i] - n_base[i + ns]) << 2) + o_base[i + (os << 1)] - n_base[i - ns];
        tdif += t * t;
    }
}
