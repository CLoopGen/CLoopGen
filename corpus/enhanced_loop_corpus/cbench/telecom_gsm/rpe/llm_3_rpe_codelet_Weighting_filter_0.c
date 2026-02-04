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
    // Variant 2: Strided Memory Access with Reverse Traversal
    // Instead of forward sequential k from 0 to 39, we traverse backwards
    // and use a fixed stride pattern on the e[] array to simulate irregular access.
    // Also, we change the access order to emphasize strided reads.

    const int offsets[] = {10, 9, 7, 6, 5, 4, 3, 1, 0};  // Reverse access order, skipping 8 and 2
    const longword coeffs[] = {-134, -374, 2054, 5741, 8192, 5741, 2054, -374, -134};

    for (k = 39; k >= 0; k--) {
        L_result = 8192 >> 1;

        // Strided and reverse-ordered access using offset list
        L_result += (e[k + offsets[0]] * coeffs[0]);  // e[k+10]
        L_result += (e[k + offsets[1]] * coeffs[1]);  // e[k+9]
        L_result += (e[k + offsets[2]] * coeffs[2]);  // e[k+7]
        L_result += (e[k + offsets[3]] * coeffs[3]);  // e[k+6]
        L_result += (e[k + offsets[4]] * coeffs[4]);  // e[k+5]
        L_result += (e[k + offsets[5]] * coeffs[5]);  // e[k+4]
        L_result += (e[k + offsets[6]] * coeffs[6]);  // e[k+3]
        L_result += (e[k + offsets[7]] * coeffs[7]);  // e[k+1]
        L_result += (e[k + offsets[8]] * coeffs[8]);  // e[k+0]

        L_result >>= 13;
        x[k] = (L_result < -32768 ? -32768 : (L_result > 32767 ? 32767 : L_result));
    }
}
