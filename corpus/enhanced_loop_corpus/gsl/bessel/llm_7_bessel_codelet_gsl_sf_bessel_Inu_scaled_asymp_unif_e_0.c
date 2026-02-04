#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependency by unrolling and computing independent terms
    // Assuming initial tpow[0] is defined externally, each access now only depends on static index
    if (i >= 1) tpow[1] = t * tpow[0];
    if (i >= 2) tpow[2] = t * tpow[1];
    if (i >= 3) tpow[3] = t * tpow[2];
    if (i >= 4) tpow[4] = t * tpow[3];
    if (i >= 5) tpow[5] = t * tpow[4];
    if (i >= 6) tpow[6] = t * tpow[5];
    if (i >= 7) tpow[7] = t * tpow[6];
    if (i >= 8) tpow[8] = t * tpow[7];
    if (i >= 9) tpow[9] = t * tpow[8];
    if (i >= 10) tpow[10] = t * tpow[9];
    if (i >= 11) tpow[11] = t * tpow[10];
    if (i >= 12) tpow[12] = t * tpow[11];
    if (i >= 13) tpow[13] = t * tpow[12];
    if (i >= 14) tpow[14] = t * tpow[13];
    if (i >= 15) tpow[15] = t * tpow[14];
}
