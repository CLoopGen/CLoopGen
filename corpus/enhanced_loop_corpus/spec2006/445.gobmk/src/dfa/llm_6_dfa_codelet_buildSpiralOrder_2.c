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
    for (k = 0; k < 21 * 21 * 4; k++) {
        j0 = order[k][0] % (4 * 21);
        if (j0 >= 2 * 21)
            j0 -= 4 * 21;
        if (j0 < -2 * 21)
            j0 += 4 * 21;
        i0 = (order[k][0] - j0) / (4 * 21);
        // Eliminate loop-carried dependency by unrolling and reordering computations
        // Introduce temporary variables to break artificial dependencies
        int temp_i[7], temp_j[7];
        for (ll = 1; ll < 8; ll++) {
            temp_i[ll-1] = transformation2[ll][0][0] * i0 + transformation2[ll][0][1] * j0;
            temp_j[ll-1] = transformation2[ll][1][0] * i0 + transformation2[ll][1][1] * j0;
            order[k][ll] = 4 * 21 * temp_i[ll-1] + temp_j[ll-1];
        }
    }
}
