#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *e;
extern word *x;
extern longword L_result;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Reordered Coefficient Application
    // Instead of accessing e[k + offset] with non-consecutive offsets (skipping k+2, k+8),
    // we precompute a temporary array that holds the relevant e values in consecutive order
    // to improve spatial locality. The coefficients are applied in sequence.

    word temp[9];  // Holds e[k] to e[k+10], skipping indices k+2 and k+8
    const longword coeffs[9] = { -134, -374, 2054, 5741, 8192, 5741, 2054, -374, -134 };

    for (k = 0; k <= 39; k++) {
        // Load elements in a consecutive pattern (but from strided original source)
        temp[0] = e[k + 0];
        temp[1] = e[k + 1];
        temp[2] = e[k + 3];  // skip k+2
        temp[3] = e[k + 4];
        temp[4] = e[k + 5];
        temp[5] = e[k + 6];
        temp[6] = e[k + 7];
        temp[7] = e[k + 9];  // skip k+8
        temp[8] = e[k + 10];

        L_result = 8192 >> 1;

        // Apply coefficients using consecutive access over temp and coeffs
        for (int i = 0; i < 9; i++) {
            L_result += (temp[i] * coeffs[i]);
        }

        L_result = ((L_result) >> 13);
        x[k] = (L_result < (-32768) ? (-32768) : (L_result > 32767 ? 32767 : L_result));
    }
}
