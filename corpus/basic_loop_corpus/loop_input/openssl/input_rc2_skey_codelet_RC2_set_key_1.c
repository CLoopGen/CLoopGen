#include <stdio.h>
#include <inttypes.h>

unsigned char key_table[256];
int len;
int i;
int j;
unsigned char *k;
unsigned int d;

void init_vars() {
    // Initialize key_table with dummy data
    for (int idx = 0; idx < 256; idx++) {
        key_table[idx] = (unsigned char)(idx * idx + 3 * idx + 1);
    }

    // Set up data size: aim for ~128KB to 1MB for measurable runtime (~0.01 sec)
    const int data_size = 256 * 1024; // 256 KB

    // Allocate memory for k
    k = (unsigned char*)__builtin_malloc(data_size);

    // Initialize k with non-zero values to affect loop behavior
    for (int idx = 0; idx < data_size; idx++) {
        k[idx] = (unsigned char)(idx % 255 + 1);
    }

    // Ensure initial conditions so that the loop runs safely:
    // Loop condition: i < 128, starting at i = len
    // We want the loop to run multiple times -> set len < 128
    len = 0;  // Start filling k from index 0
    i = len;  // Will be incremented in loop

    // Initialize j to a valid index in k; since we access k[j], and j increments with i,
    // we need j to start such that j + (128 - len) < data_size
    j = 1024;  // Start j at offset within allocated buffer

    // Initialize d to a small value
    d = 1;
}