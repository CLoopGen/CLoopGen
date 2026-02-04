#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word *dp;
int lambda;
word Nc;
word wt[40];
longword L_max;

static word dp_buffer[256 * 1024]; // ~512KB of data (256k short elements)

void init_vars() {
    // Initialize wt array with non-zero values to allow meaningful computation
    for (int i = 0; i < 40; i++) {
        wt[i] = (word)(i + 1);
    }

    // Initialize dp to point to the center of dp_buffer to allow negative indexing from -lambda (max 120)
    // Ensure that dp[39 - lambda] is valid when lambda=40 -> index = -81, and when lambda=120 -> index = -81
    // So we need at least 81 elements before dp[0]
    dp = dp_buffer + 128;  // Reserve space for negative indices down to -128

    // Initialize buffer with non-zero values
    for (int i = 0; i < 256 * 1024; i++) {
        dp_buffer[i] = (word)((i * 7) & 0x7FFF); // Arbitrary pattern
    }

    // Initialize L_max to a very small value to ensure first result will be larger
    L_max = -9223372036854775807LL;

    // Initialize Nc to a known safe value
    Nc = 0;
}