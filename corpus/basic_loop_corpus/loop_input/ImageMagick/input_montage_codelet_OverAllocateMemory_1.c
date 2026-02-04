#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t extent;

static size_t calculate_optimal_length() {
    struct timeval start, end;
    size_t temp_length = 1 << 20; 
    volatile size_t dummy = 0;
    
    do {
        gettimeofday(&start, NULL);
        for (extent = 256; extent < temp_length; extent *= 2) {
            dummy++; 
        }
        gettimeofday(&end, NULL);

        long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        if (elapsed >= 10000) break; 

        temp_length *= 2;
    } while (temp_length <= (256 << 20));

    return temp_length;
}

void init_vars() {
    length = calculate_optimal_length();
    extent = 0;
}