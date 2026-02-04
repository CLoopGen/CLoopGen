#include <stdio.h>

#include <inttypes.h>

extern unsigned char *rsa_in;
extern size_t rsa_inlen;
extern size_t i;
extern unsigned char ctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Two-Element Swapping from Both Ends (unrolled-like consecutive access)
    for (i = 0; i < rsa_inlen / 4; i++) {
        size_t left1 = i;
        size_t left2 = i + 1;
        size_t right1 = rsa_inlen - 1 - i;
        size_t right2 = rsa_inlen - 2 - i;

        // Swap first pair
        ctmp = rsa_in[left1];
        rsa_in[left1] = rsa_in[right1];
        rsa_in[right1] = ctmp;

        // Swap second pair
        ctmp = rsa_in[left2];
        rsa_in[left2] = rsa_in[right2];
        rsa_in[right2] = ctmp;
    }
}
