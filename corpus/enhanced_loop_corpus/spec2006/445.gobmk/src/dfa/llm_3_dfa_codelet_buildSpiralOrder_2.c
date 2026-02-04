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
    int base_offset = 4 * 21;
    for (k = 0; k < 21 * 21 * 4; k += 4) { // Strided access: process every 4th element
        for (int stride = 0; stride < 4 && (k + stride) < 21 * 21 * 4; stride++) {
            int idx = k + stride;
            j0 = order[idx][0] % base_offset;
            if (j0 >= 2 * 21)
                j0 -= base_offset;
            else if (j0 < -2 * 21)
                j0 += base_offset;
            i0 = (order[idx][0] - j0) / base_offset;

            for (ll = 1; ll < 8; ll++) {
                const int (*t)[2] = transformation2[ll];
                i = t[0][0] * i0 + t[0][1] * j0;
                j = t[1][0] * i0 + t[1][1] * j0;
                order[idx][ll] = base_offset * i + j;
            }
        }
    }
}
