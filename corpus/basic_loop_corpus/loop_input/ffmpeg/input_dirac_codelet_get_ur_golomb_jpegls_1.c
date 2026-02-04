#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit;
unsigned int re_index;
__attribute__((unused)) unsigned int re_cache;
unsigned int re_size_plus8;
int i;

void init_vars() {
    // Set up parameters to ensure the loop runs for approximately desired time
    // The loop condition depends on re_cache and bit shifting behavior
    
    re_cache = 0x40000000u;  // Start with high bit set near top, so shift-out takes many iterations
    re_index = 0;
    re_size_plus8 = 32;      // Typical value to allow index growth
    i = 0;
    limit = 10000000;        // Large enough to take ~0.01 seconds with tight inner loop
}

// Explicitly define all extern variables at file scope
int limit;
unsigned int re_index;
__attribute__((unused)) unsigned int re_cache;
unsigned int re_size_plus8;
int i;