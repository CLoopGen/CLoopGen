#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short *x;
unsigned short *y;
unsigned int a;
int i;
unsigned int carry;

static unsigned short *x_buffer;
static unsigned short *y_buffer;
static size_t data_size = 1 << 20; // 1MB of data (adjustable)

void init_vars() {
    size_t num_elements = data_size / sizeof(unsigned short);
    
    x_buffer = aligned_alloc(32, num_elements * sizeof(unsigned short));
    y_buffer = aligned_alloc(32, num_elements * sizeof(unsigned short));
    
    if (!x_buffer || !y_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < num_elements; ++idx) {
        x_buffer[idx] = (unsigned short)(idx & 65535);
        y_buffer[idx] = (unsigned short)((idx + 100) & 65535);
    }
    
    x = &x_buffer[num_elements - 1];
    y = &y_buffer[num_elements - 1];
    
    carry = 1;
    a = 0;
    i = 0;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}

__attribute__((destructor))
static void destructor_free() {
    free(x_buffer);
    free(y_buffer);
}