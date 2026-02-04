#include <stdio.h>

#include <inttypes.h>

extern unsigned int i;
extern unsigned char hmac_key[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    unsigned int indices[sizeof(hmac_key)];
    for (i = 0; i < sizeof(hmac_key); i++) {
        indices[i] = i;
    }
    for (i = 0; i < sizeof(hmac_key); i++) {
        hmac_key[indices[i]] ^= 54;
    }
}
