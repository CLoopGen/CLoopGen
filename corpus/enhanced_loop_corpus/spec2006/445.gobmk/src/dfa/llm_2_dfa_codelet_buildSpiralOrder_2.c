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



void loop() {
    for (k = 0; k < 21 * 21 * 4; k++) {
        j0 = order[k][0] % (4 * 21);
        if (j0 >= 2 * 21)
            j0 -= 4 * 21;
        if (j0 < -2 * 21)
            j0 += 4 * 21;
        i0 = (order[k][0] - j0) / (4 * 21);
        for (ll = 1; ll < 8; ll++) {
            int ti0 = transformation2[ll][0][0];
            int tj0 = transformation2[ll][0][1];
            int tji = transformation2[ll][1][0];
            int tjj = transformation2[ll][1][1];
            i = ti0 * i0 + tj0 * j0;
            j = tji * i0 + tjj * j0;
            order[k][ll] = (4 * 21) * i + j;
        }
    }
}
