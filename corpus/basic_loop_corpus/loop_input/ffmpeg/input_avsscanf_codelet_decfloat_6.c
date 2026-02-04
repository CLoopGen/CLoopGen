#include <stdint.h>
#include <stdlib.h>

uint32_t x[128];
int k;
int a;
int z;
uint32_t carry;

void init_vars() {
    // Initialize the array x with non-zero values to ensure meaningful computation
    for (int i = 0; i < 128; i++) {
        x[i] = rand() % 1000000000;
    }

    // Set initial value of carry
    carry = rand() % 1000000; // Keep initial carry relatively small

    // Ensure z is within valid range [0,127], since it's used as index via (z-1 & 127)
    z = rand() % 128;

    // Set a to a valid index in circular buffer, ensuring loop termination
    a = rand() % 128;

    // Ensure that z-1 & 127 is valid and that the loop will eventually hit a
    // No further adjustment needed — modulo arithmetic with & 127 ensures bounds
}