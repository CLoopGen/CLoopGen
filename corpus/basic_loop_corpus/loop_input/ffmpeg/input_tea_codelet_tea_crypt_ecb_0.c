#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t v0 = 0x12345678;
uint32_t v1 = 0xabcdef01;
int rounds = 1000000;
uint32_t k0 = 0x9ae16a3b;
uint32_t k1 = 0x4b9e4657;
uint32_t k2 = 0x6d81182c;
uint32_t k3 = 0x1e8c7d2f;
int i = 0;
uint32_t delta = 0x9e3779b9;
uint32_t sum = 0xc6ef3720;

void init_vars() {
    // Recompute sum based on rounds to ensure proper loop behavior
    sum = delta * (rounds / 2);
    v0 += 0x11111111;
    v1 += 0x22222222;
}