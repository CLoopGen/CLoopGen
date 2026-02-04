#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t v0 = 0x12345678;
uint32_t v1 = 0x87654321;
int rounds = 1000000;
uint32_t k0 = 0xA5A5A5A5;
uint32_t k1 = 0xB6B6B6B6;
uint32_t k2 = 0xC7C7C7C7;
uint32_t k3 = 0xD8D8D8D8;
int i = 0;
uint32_t sum = 0;
uint32_t delta = 0x9E3779B9;

void init_vars() {
    // Initialize variables to ensure consistent and safe execution
    v0 = 0x12345678;
    v1 = 0x87654321;
    rounds = 1000000;  // Adjusted to target ~0.01 sec runtime
    k0 = 0xA5A5A5A5;
    k1 = 0xB6B6B6B6;
    k2 = 0xC7C7C7C7;
    k3 = 0xD8D8D8D8;
    i = 0;
    sum = 0;
    delta = 0x9E3779B9;  // Standard delta for TEA-like ciphers
}