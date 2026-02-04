#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char **p;
size_t *length;
int c;
ssize_t i;
unsigned char buffer[2];

static unsigned char *data_ptr;
static size_t data_length;

void init_vars() {
    data_length = 16777216; // ~16MB to achieve around 0.01s runtime on modern CPU
    data_ptr = (unsigned char*)malloc(data_length);
    if (!data_ptr) {
        exit(1);
    }
    
    // Initialize with non-zero data to avoid potential issues with zero-initialized memory
    for (size_t j = 0; j < data_length; j++) {
        data_ptr[j] = (unsigned char)(j & 0xFF);
    }
    
    // Allocate and initialize p to point to data_ptr
    p = (unsigned char**)malloc(sizeof(unsigned char*));
    if (!p) {
        free(data_ptr);
        exit(1);
    }
    *p = data_ptr;
    
    // Allocate and initialize length
    length = (size_t*)malloc(sizeof(size_t));
    if (!length) {
        free(p);
        free(data_ptr);
        exit(1);
    }
    *length = data_length;
    
    // Initialize other variables
    c = 0;
    i = 0;
    buffer[0] = 0;
    buffer[1] = 0;
}