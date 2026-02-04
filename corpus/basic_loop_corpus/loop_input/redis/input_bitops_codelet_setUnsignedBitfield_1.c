#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

unsigned char *p;
uint64_t offset;
uint64_t bits;
uint64_t value;
uint64_t byte;
uint64_t bit;
uint64_t byteval;
uint64_t bitval;
uint64_t j;

#define DATA_SIZE (128 << 20) // 128 MB

void init_vars() {
    // Allocate large buffer to ensure loop runs for desired duration
    static unsigned char buffer[DATA_SIZE];
    
    p = buffer;
    
    // Set up problem size to access within allocated bounds
    bits = 10000000; // ~10 million iterations to target ~0.01 sec on modern CPU
    
    // Ensure offset + (bits >> 3) doesn't exceed buffer
    // We need at most: initial_byte + ceil(bits / 8) <= DATA_SIZE
    offset = 0;
    
    // Pick non-zero test value with varying bit pattern
    value = 0xABCDEF1234567890ULL;
    
    // Initialize other working variables to zero
    byte = 0;
    bit = 0;
    byteval = 0;
    bitval = 0;
    j = 0;
}