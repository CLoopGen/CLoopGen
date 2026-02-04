#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

Hashvalue (*ko_hash)[1] = NULL;
Hash_data *target = NULL;
int ko_pos = 0;
int i = 0;

void init_vars() {
    const int num_hashes = 400;
    const int hash_size_in_long = 64 / (8 * sizeof(long));
    const int total_data_size = 16 * 1024 * 1024; // ~16 MB for ~0.01 sec target
    const int array_size = total_data_size / (num_hashes * hash_size_in_long * sizeof(Hashvalue));
    
    // Ensure at least one block
    const int effective_array_size = array_size < 1 ? 1 : array_size;

    // Allocate ko_hash as a 2D array: [400][effective_array_size]
    ko_hash = calloc(400, sizeof(Hashvalue[effective_array_size]));
    if (!ko_hash) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Allocate target array with same size to match access pattern
    target = malloc(sizeof(Hash_data) + sizeof(Hashvalue) * (hash_size_in_long - 1));
    if (!target) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize all data with deterministic non-zero values
    srand(time(NULL));
    for (int idx = 0; idx < 400; idx++) {
        for (int j = 0; j < effective_array_size; j++) {
            ko_hash[idx][j] = rand() | ((Hashvalue)rand() << 32);
        }
    }

    for (int j = 0; j < hash_size_in_long; j++) {
        target->hashval[j] = rand() | ((Hashvalue)rand() << 32);
    }

    // Set ko_pos within valid range [0, 399]
    ko_pos = rand() % 400;
}