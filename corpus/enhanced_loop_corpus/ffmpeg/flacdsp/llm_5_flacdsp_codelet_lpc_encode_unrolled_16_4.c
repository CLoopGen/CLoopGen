#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int len;
extern int order;
extern  int32_t *coefs;
extern int shift;
extern int big;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = order; i < len; i += 2) {
    int s = smp[i - order];
    int32_t p0 = 0, p1 = 0;

    // Control Dependency Change: Introduce early termination condition based on coefficient magnitude
    // If the first coefficient is zero, skip this iteration entirely
    if (coefs[0] == 0) {
        res[i] = smp[i];
        res[i + 1] = smp[i + 1];
        continue;
    }

    // Always execute at least one term (order >= 1 assumed)
    {
        int c = coefs[0];
        p0 += c * s;
        s = smp[i - 0]; // i - 1 + 1 = i
        p1 += c * s;
    }

    // Add conditional execution for higher orders: only process deeper taps if shift is non-zero
    // This introduces a new control path based on shift value
    if (shift > 0) {
        switch (order) {
            case 32:
                {
                    int c = coefs[31];
                    p0 += c * smp[i - 31];
                    s = smp[i - 30];
                    p1 += c * s;
                }
            case 31:
                {
                    int c = coefs[30];
                    p0 += c * s;
                    s = smp[i - 29];
                    p1 += c * s;
                }
            case 30:
                {
                    int c = coefs[29];
                    p0 += c * s;
                    s = smp[i - 28];
                    p1 += c * s;
                }
            // Fallthrough unrolling continues...
            case 29: p0 += coefs[28] * smp[i - 28]; s = smp[i - 27]; p1 += coefs[28] * s;
            case 28: p0 += coefs[27] * smp[i - 27]; s = smp[i - 26]; p1 += coefs[27] * s;
            case 27: p0 += coefs[26] * smp[i - 26]; s = smp[i - 25]; p1 += coefs[26] * s;
            case 26: p0 += coefs[25] * smp[i - 25]; s = smp[i - 24]; p1 += coefs[25] * s;
            case 25: p0 += coefs[24] * smp[i - 24]; s = smp[i - 23]; p1 += coefs[24] * s;
            case 24: p0 += coefs[23] * smp[i - 23]; s = smp[i - 22]; p1 += coefs[23] * s;
            case 23: p0 += coefs[22] * smp[i - 22]; s = smp[i - 21]; p1 += coefs[22] * s;
            case 22: p0 += coefs[21] * smp[i - 21]; s = smp[i - 20]; p1 += coefs[21] * s;
            case 21: p0 += coefs[20] * smp[i - 20]; s = smp[i - 19]; p1 += coefs[20] * s;
            case 20: p0 += coefs[19] * smp[i - 19]; s = smp[i - 18]; p1 += coefs[19] * s;
            case 19: p0 += coefs[18] * smp[i - 18]; s = smp[i - 17]; p1 += coefs[18] * s;
            case 18: p0 += coefs[17] * smp[i - 17]; s = smp[i - 16]; p1 += coefs[17] * s;
            case 17: p0 += coefs[16] * smp[i - 16]; s = smp[i - 15]; p1 += coefs[16] * s;
            case 16: p0 += coefs[15] * smp[i - 15]; s = smp[i - 14]; p1 += coefs[15] * s;
            case 15: p0 += coefs[14] * smp[i - 14]; s = smp[i - 13]; p1 += coefs[14] * s;
            case 14: p0 += coefs[13] * smp[i - 13]; s = smp[i - 12]; p1 += coefs[13] * s;
            case 13: p0 += coefs[12] * smp[i - 12]; s = smp[i - 11]; p1 += coefs[12] * s;
            case 12: p0 += coefs[11] * smp[i - 11]; s = smp[i - 10]; p1 += coefs[11] * s;
            case 11: p0 += coefs[10] * smp[i - 10]; s = smp[i - 9]; p1 += coefs[10] * s;
            case 10: p0 += coefs[9] * smp[i - 9]; s = smp[i - 8]; p1 += coefs[9] * s;
            case 9:  p0 += coefs[8] * smp[i - 8]; s = smp[i - 7]; p1 += coefs[8] * s;
            case 8:  p0 += coefs[7] * smp[i - 7]; s = smp[i - 6]; p1 += coefs[7] * s;
            case 7:  p0 += coefs[6] * smp[i - 6]; s = smp[i - 5]; p1 += coefs[6] * s;
            case 6:  p0 += coefs[5] * smp[i - 5]; s = smp[i - 4]; p1 += coefs[5] * s;
            case 5:  p0 += coefs[4] * smp[i - 4]; s = smp[i - 3]; p1 += coefs[4] * s;
            case 4:  p0 += coefs[3] * smp[i - 3]; s = smp[i - 2]; p1 += coefs[3] * s;
            case 3:  p0 += coefs[2] * smp[i - 2]; s = smp[i - 1]; p1 += coefs[2] * s;
            case 2:  p0 += coefs[1] * smp[i - 1]; s = smp[i];     p1 += coefs[1] * s;
            // case 1 already handled above
        }
    } else {
        // When shift == 0, only use first coefficient (simulates reduced precision mode)
        // No additional taps are applied
    }

    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
}
}
