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
    size_t test_length = 1 << 20; 
    volatile size_t dummy = 1;
    
    gettimeofday(&start, NULL);
    for (extent = 256; extent < test_length; extent *= 2) {
        dummy *= extent; 
    }
    gettimeofday(&end, NULL);
    
    long elapsed = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    double factor = 10000.0 / elapsed; 
    size_t target = (size_t)(test_length * factor);
    
    if (target < (1 << 20)) target = (1 << 20);
    if (target > (256 << 20)) target = (256 << 20);
    
    return target;
}

void init_vars() {
    length = get_optimal_length();
    extent = 0;
}