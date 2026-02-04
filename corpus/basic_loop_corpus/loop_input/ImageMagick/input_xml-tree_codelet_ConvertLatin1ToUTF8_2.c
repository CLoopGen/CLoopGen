#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *restrict content;
unsigned char *restrict p;
size_t length;

static unsigned char *data_buffer;
static size_t data_size;

void init_vars() {
    // Allocate approximately 64MB to target ~0.01s runtime on modern CPUs
    data_size = 64 * 1024 * 1024;
    data_buffer = (unsigned char*)malloc(data_size);
    
    if (!data_buffer) {
        exit(1);
    }
    
    // Initialize with pseudo-random data, ensuring a null terminator at the end
    srand(time(NULL));
    for (size_t i = 0; i < data_size - 1; i++) {
        data_buffer[i] = rand() & 0xFF;
    }
    data_buffer[data_size - 1] = '\x00'; // Null terminator to stop the loop
    
    // Initialize external pointers and variables
    content = data_buffer;
    p = content;
    length = 0;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
// Caller is responsible for eventually freeing resources if needed