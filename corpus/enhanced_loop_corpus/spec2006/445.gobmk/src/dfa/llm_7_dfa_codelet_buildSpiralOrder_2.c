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
    // Introduce loop-carried dependence by accumulating a synthetic state across iterations
    // This creates a WAW and RAW dependency on variable 'i' and 'j' across loop iterations
    int carry_i = 0, carry_j = 0;
    for (k = 0; k < 21 * 21 * 4; k++) {
        j0 = order[k][0] % (4 * 21);
        if (j0 >= 2 * 21)
            j0 -= 4 * 21;
        if (j0 < -2 * 21)
            j0 += 4 * 21;
        i0 = (order[k][0] - j0) / (4 * 21);

        // Make each iteration depend on the previous via carry_i/carry_j (RAW & WAW)
        i0 += carry_i;  // Artificially introduce dependency from prior iteration
        j0 += carry_j;

        for (ll = 1; ll < 8; ll++) {
            i = transformation2[ll][0][0] * i0 + transformation2[ll][0][1] * j0;
            j = transformation2[ll][1][0] * i0 + transformation2[ll][1][1] * j0;
            order[k][ll] = 4 * 21 * i + j;
        }

        // Update carried state (creates WAW on carry_i/j)
        carry_i = i % 10;  // Arbitrary feedback to create loop-carried dep
        carry_j = j % 10;
    }
}
