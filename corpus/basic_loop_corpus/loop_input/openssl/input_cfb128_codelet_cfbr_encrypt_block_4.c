#include <stdio.h>
#include <inttypes.h>

unsigned char ovec[1024 * 128]; // Large enough to support large num values safely
unsigned char ivec[16];
int n;
int rem;
int num;

void init_vars() {
    // Initialize rem to a valid shift value between 1 and 7
    rem = 3;
    
    // Ensure that n + num + 1 < sizeof(ovec) for all n in [0,15]
    // So num must be <= sizeof(ovec) - 17
    num = (1024 * 128) - 32; // Leave some margin
    
    // Initialize ovec with non-zero data to make shifts meaningful
    for (int i = 0; i < sizeof(ovec); ++i) {
        ovec[i] = (unsigned char)(i & 0xFF);
    }
}