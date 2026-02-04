#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB to target ~0.01 sec runtime

int16_t *ip;
int A = 1;
int B = 2;
int C = 3;
int D = 4;
int Ad = 5;
int Bd = 6;
int Cd = 0;
int Dd = 0;
int E = 7;
int F = 8;
int G = 9;
int H = 10;
int Ed = 0;
int Gd = 0;
int Add = 0;
int Bdd = 0;
int Fd = 0;
int Hd = 0;
int i = 0;

static int16_t *ip_storage;

void init_vars() {
    // Allocate memory with sufficient size to allow ip to be incremented 8 times
    // Each increment moves by 1, and we access indices 0*8 through 7*8 => max offset 56
    // So we need at least 57 elements per block, but we'll have multiple blocks due to loop iterations
    const int total_elements = DATA_SIZE / sizeof(int16_t);
    
    ip_storage = (int16_t*)calloc(total_elements, sizeof(int16_t));
    if (!ip_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize data so that the condition triggers (set some non-zero values)
    for (int j = 0; j < 8; j++) {
        ip_storage[j * 8] = (j % 2 == 0) ? 1 : -1; // Ensure OR condition is true
    }

    // Set initial ip to start of storage
    ip = ip_storage;
}