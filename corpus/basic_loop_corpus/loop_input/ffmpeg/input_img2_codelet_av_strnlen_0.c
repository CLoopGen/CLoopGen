#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static const size_t target_time_ns = 10000000; // 10 ms in nanoseconds

void init_vars() {
    struct timespec start, end;
    
    // Estimate clock resolution and determine data size for ~10ms runtime
    size_t data_size = 1024 * 1024; // Start with 1MB
    int iterations = 100;
    
    while (data_size <= 256 * 1024 * 1024) { // Up to 256MB
        internal_s = calloc(data_size + 1, sizeof(char));
        if (!internal_s) {
            data_size *= 2;
            continue;
        }
        
        s = internal_s;
        len = data_size;
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int iter = 0; iter < iterations; iter++) {
            for (i = 0; i < len && s[i]; i++)
                ;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        
        long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
        
        free(internal_s);
        internal_s = NULL;
        
        if (elapsed_ns >= target_time_ns) {
            data_size = (data_size * target_time_ns) / elapsed_ns;
            data_size = data_size < 1024*1024 ? 1024*1024 : data_size;
            break;
        }
        
        data_size *= 2;
    }
    
    if (data_size > 256 * 1024 * 1024)
        data_size = 256 * 1024 * 1024;
    
    internal_s = calloc(data_size + 1, sizeof(char));
    if (!internal_s) {
        data_size = 128 * 1024 * 1024;
        internal_s = calloc(data_size + 1, sizeof(char));
    }
    
    // Fill with null bytes so loop runs full length
    memset(internal_s, 0, data_size);
    internal_s[data_size] = 1; // Ensure termination condition is met
    
    s = internal_s;
    len = data_size;
    i = 0;
}