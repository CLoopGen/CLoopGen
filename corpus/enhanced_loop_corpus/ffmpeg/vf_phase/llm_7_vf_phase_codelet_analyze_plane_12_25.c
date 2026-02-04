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
    uint16_t *rend = nptr + w;

    // Introduce temporary accumulators to break WAW and WAR dependencies
    int64_t temp_pdif = pdif;
    int64_t temp_tdif = tdif;

    for (int i = 0; i < w; i++) {
        // Remove pointer arithmetic dependency on side effects by using index
        uint16_t val_n = nptr[i];
        uint16_t val_nn = nptr[i + ns];
        uint16_t val_nns = nptr[i + (ns << 1)];
        uint16_t val_nneg = nptr[i - ns];

        int t_n = ((val_n - val_nn) << 2) + val_nns - val_nneg;
        temp_pdif += t_n * t_n;

        uint16_t val_o = optr[i];
        uint16_t val_ons = optr[i + (os << 1)];
        int t_o = ((val_o - val_nn) << 2) + val_ons - val_nneg;
        temp_tdif += t_o * t_o;
    }

    // Update globals only once after loop (reducing WAW)
    pdif = temp_pdif;
    tdif = temp_tdif;

    // Update pointers to maintain semantics
    nptr = rend;
    optr += w;
}
