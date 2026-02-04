#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int lut_nmsedec_ref[128];
extern int lut_nmsedec_ref0[128];
extern int lut_nmsedec_sig[128];
extern int lut_nmsedec_sig0[128];
extern int i;
extern int a;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < (1 << 7); i++) {
    lut_nmsedec_sig[i] = (((3 * i << (13 - (7 - 1))) - (9 << 11)) > (0) ? ((3 * i << (13 - (7 - 1))) - (9 << 11)) : (0));
    lut_nmsedec_sig0[i] = (((i * i + (1 << (7 - 1) - 1) & mask) << 1) > (0) ? ((i * i + (1 << (7 - 1) - 1) & mask) << 1) : (0));
    a = (i >> (7 - 2) & 2) + 1;
    lut_nmsedec_ref[i] = (((a - 2) * (i << (13 - (7 - 1))) + (1 << 13) - (a * a << 11)) > (0) ? ((a - 2) * (i << (13 - (7 - 1))) + (1 << 13) - (a * a << 11)) : (0));
    lut_nmsedec_ref0[i] = ((((i * i - (i << 7) + (1 << 2 * (7 - 1)) + (1 << ((7 - 1) - 1))) & mask) << 1) > (0) ? (((i * i - (i << 7) + (1 << 2 * (7 - 1)) + (1 << ((7 - 1) - 1))) & mask) << 1) : (0));
}

}
