#include <stdint.h>
#include <stdlib.h>

uint64_t in = 0x123456789ABCDEF0ULL;

uint8_t *shuffle;
int shuffle_len;
int i;
uint64_t res;

void init_vars() {
    shuffle_len = (1 << 24); // Approximately 16.7 million elements for ~0.01 sec runtime
    shuffle = malloc(shuffle_len * sizeof(uint8_t));
    if (!shuffle) exit(1);
    
    // Initialize shuffle array with valid bit indices (0 to 63)
    for (int idx = 0; idx < shuffle_len; idx++) {
        shuffle[idx] = idx % 64;
    }
    
    i = 0;
    res = 1;
}