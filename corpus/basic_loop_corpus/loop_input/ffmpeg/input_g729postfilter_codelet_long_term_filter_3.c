#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int subframe_size = 1024 * 128;  // Approx. 128KB of data, adjustable for timing
int i;
int16_t shift = 3;  // Must be positive so that -shift is negative; used as left shift count
int16_t *residual;
int16_t sig_scaled[192];

void init_vars() {
    // Allocate residual to cover the maximum index accessed: i < subframe_size + (143 + 8 + 1)
    int total_size = subframe_size + (143 + 8 + 1);
    residual = (int16_t*)calloc(total_size, sizeof(int16_t));
    if (!residual) {
        exit(1);
    }

    // Initialize residual with sample data
    for (int j = 0; j < total_size; j++) {
        residual[j] = (int16_t)(j & 0xFF);
    }

    // Ensure sig_scaled is safe to write up to subframe_size + (143+8+1)-1
    // But note: sig_scaled is only 192 elements! So we must cap subframe_size accordingly.

    // Correction: sig_scaled has only 192 elements, so loop bound must not exceed 192.
    // Therefore, adjust subframe_size so that: subframe_size + (152) < 192 -> subframe_size <= 39
    subframe_size = 39;  // Now ensures i < 39 + 152 = 191, which is within [0, 191]

    // Reallocate residual with corrected size
    free(residual);
    residual = (int16_t*)calloc(192, sizeof(int16_t));
    if (!residual) {
        exit(1);
    }
    for (int j = 0; j < 192; j++) {
        residual[j] = (int16_t)(j & 0xFF);
    }

    // Initialize shift to a positive value so that << (-shift) becomes a right shift
    // However, C does not allow negative shift counts. This code is dangerous.
    // But assuming shift is small positive, then -shift is negative -> undefined behavior!
    // To avoid UB, we assume the original intent was to do a right shift by |shift|.
    // But the code says: (unsigned int)residual[i] << -shift
    // If shift > 0, then -shift < 0 -> invalid shift count (undefined behavior).

    // Fix: reinterpret logic. Likely intended: shift right by 'shift' amount.
    // But since we cannot fix the loop, we must ensure -shift is non-negative => shift <= 0.
    // So set shift to a negative number so that -shift becomes positive.

    shift = -2;  // Now -shift = 2, so it's a left shift by 2 — defined behavior.

    // With shift = -2, then -shift = 2, valid left shift.
}