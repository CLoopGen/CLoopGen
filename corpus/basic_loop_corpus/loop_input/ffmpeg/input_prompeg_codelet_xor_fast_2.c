#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *in1;
uint8_t *in2;
uint8_t *out;
int i;
int n;

void init_vars() {
    n = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec on typical CPU

    in1 = (uint8_t*)malloc(n * sizeof(uint8_t));
    in2 = (uint8_t*)malloc(n * sizeof(uint8_t));
    out = (uint8_t*)malloc(n * sizeof(uint8_t));

    if (!in1 || !in2 || !out) {
        exit(1);
    }

    for (int j = 0; j < n; j++) {
        in1[j] = (uint8_t)(j & 0xFF);
        in2[j] = (uint8_t)((j ^ 0xAA) & 0xFF);
    }
}