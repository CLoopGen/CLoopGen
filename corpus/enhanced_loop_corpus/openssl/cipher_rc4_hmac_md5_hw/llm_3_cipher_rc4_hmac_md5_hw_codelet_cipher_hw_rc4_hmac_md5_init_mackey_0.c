#include <stdio.h>

#include <inttypes.h>

extern unsigned int i;
extern unsigned char hmac_key[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access pattern
    size_t size = sizeof(hmac_key);
    unsigned int indices[64];
    for (i = 0; i < size; i++) {
        indices[i] = i; // Populate index map in order (could be randomized in more complex cases)
    }
    for (i = 0; i < size; i++) {
        hmac_key[indices[i]] ^= 54;
    }
}
