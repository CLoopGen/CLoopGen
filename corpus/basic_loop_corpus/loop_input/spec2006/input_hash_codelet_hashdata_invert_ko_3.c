#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

#define ARRAY_SIZE 256 * 1024 * sizeof(long)  // ~256KB per array to target ~0.01s runtime
#define HD_COUNT (ARRAY_SIZE / sizeof(Hashvalue))

Hash_data *hd;
Hashvalue (*ko_hash)[1];
int pos = 0;
int i = 0;

void init_vars() {
    srand((unsigned int)time(NULL));

    // Allocate hd with enough space to support index up to (64/(8*sizeof(long)))-1 safely
    int max_index = (64 / (8 * sizeof(long)));
    hd = (Hash_data*)calloc(HD_COUNT, sizeof(Hash_data));
    
    // Ensure we can access at least max_index elements in hd->hashval
    if (max_index > 1) {
        // Reallocate to ensure sufficient size for indexing
        free(hd);
        hd = (Hash_data*)calloc(max_index, sizeof(Hashvalue));
    }

    // Allocate ko_hash as a 2D array: [400][1] but make second dimension large enough
    ko_hash = (Hashvalue(*)[1])calloc(400 * HD_COUNT, sizeof(Hashvalue));
    
    // Initialize all data with pseudo-random values
    for (int idx = 0; idx < HD_COUNT; idx++) {
        if (hd) {
            hd[idx].hashval[0] = rand() ^ (rand() << 16);
        }
        for (int j = 0; j < 1; j++) {
            ko_hash[idx][j] = rand() ^ (rand() << 16);
        }
    }

    // Set pos within valid range [0,399]
    pos = rand() % 400;
}