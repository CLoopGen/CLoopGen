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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Access every 4th element to simulate strided, sparse traversal
    // This increases spatial distance between accesses, stressing cache performance
    const int stride = 4;
    uint16_t *nend = nptr + w;
    pdif = bdif = 0; // Reset accumulators
    for (int i = 0; nptr + i < nend; i += stride) {
        uint16_t *curr_n = nptr + i;
        uint16_t *curr_o = optr + i;
        // Apply boundary check for neighbor accesses
        if (i >= ns && i + (ns << 1) < w) {
            t = ((*curr_n - curr_n[ns]) << 2) + curr_n[(ns) << 1] - curr_n[-ns];
            pdif += t * t;
            t = ((*curr_n - curr_o[os]) << 2) + curr_n[(ns) << 1] - curr_o[-os];
            bdif += t * t;
        }
    }
    // Update nptr and optr to reflect full advancement (simulate original side effect)
    nptr = nend;
    optr += w;
}
