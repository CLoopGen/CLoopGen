#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t extent;

static size_t get_optimal_length() {
    struct timeval start, end;
    size_t test_length = 1 << 20; // Start with 1MB
    volatile size_t dummy = 0;
    
    // Warm-up
    for (int i = 0; i < 1000; ++i) {
        dummy += i;
    }
    
    length = test_length;
    gettimeofday(&start, NULL);
    
    for (extent = 256; extent < length; extent *= 2) {
        dummy += extent;
    }
    
    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    
    // Scale length to achieve ~0.01 seconds
    if (elapsed > 0) {
        double scale = 0.01 / elapsed;
        test_length = (size_t)(test_length * scale);
    }
    
    // Clamp to reasonable bounds
    if (test_length < (1 << 20)) test_length = (1 << 20);      // Min 1MB
    if (test_length > (256 << 20)) test_length = (256 << 20);  // Max 256MB
    
    return test_length;
}

void init_vars() {
    length = get_optimal_length();
    extent = 0;
}