#include <stdio.h>

#include <inttypes.h>

extern const int transformation2[8][2][2];
extern int order[1764][8];
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int k;
extern int ll;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
for (k = 0; k < 21 * 21 * 8; k += 2) {
    int local_order = order[k % 1764][0];
    j0 = local_order % (4 * 21);
    i0 = (local_order - j0) / (4 * 21);
    if (j0 >= 2 * 21) j0 -= 4 * 21;
    else if (j0 < -2 * 21) j0 += 4 * 21;

    for (ll = 1; ll < 4; ll++) {
        int transformed_i = transformation2[ll][0][0] * i0 + transformation2[ll][0][1] * j0;
        int transformed_j = transformation2[ll][1][0] * i0 + transformation2[ll][1][1] * j0;
        order[k % 1764][ll] = 4 * 21 * transformed_i + transformed_j;

        transformed_i = transformation2[ll+4][0][0] * i0 + transformation2[ll+4][0][1] * j0;
        transformed_j = transformation2[ll+4][1][0] * i0 + transformation2[ll+4][1][1] * j0;
        order[(k+1) % 1764][ll+4] = 4 * 21 * transformed_i + transformed_j;
    }
}
}
