#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *property;
size_t tag;
ssize_t i;
int c;
size_t n;

static char data_buffer[131072]; // 128KB of input data

void init_vars() {
    n = sizeof(data_buffer) - 1;
    
    // Fill buffer with valid hex characters to ensure full loop execution
    for (size_t idx = 0; idx < n; idx++) {
        int val = rand() % 16;
        if (val < 10)
            data_buffer[idx] = '0' + val;
        else
            data_buffer[idx] = 'A' + (val - 10);
    }
    data_buffer[n] = '\0'; // Ensure null termination if needed
    
    // Initialize pointers and variables
    property = data_buffer;
    tag = 0;
    i = 0;
    c = 0;
    
    // Warm up random number generator
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&n));
}