#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *decoded;
int coeffs[32];
int pred_order = 8;
int qlevel = 5;
int len;
int i;
int j;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)
    len = total_size / sizeof(int32_t);

    // Ensure that pred_order is at least 2 and less than len, and that we don't overflow in the loop
    if (pred_order >= len) {
        pred_order = len - 1;
    }

    // Allocate decoded array with padding to prevent out-of-bounds access
    // The loop accesses up to decoded[j+1] where j goes up to pred_order, so we need extra space
    size_t decoded_size = len + pred_order + 2;
    int32_t *decoded_base = calloc(decoded_size, sizeof(int32_t));
    if (!decoded_base) {
        exit(1);
    }
    decoded = decoded_base;

    // Initialize coeffs with non-zero values to make computation meaningful
    for (int k = 0; k < 32; k++) {
        coeffs[k] = (k % 7) + 1;
    }

    // Initialize part of decoded array to avoid undefined behavior
    for (size_t k = 0; k < len + pred_order + 2; k++) {
        decoded_base[k] = (int32_t)(k % 31);
    }

    // Set initial loop variable state if needed; will be overridden in loop
    i = 0;
    j = 0;
}