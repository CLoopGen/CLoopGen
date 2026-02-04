#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;

static unsigned int *Yo_data;
static int *Y_data;
unsigned int *Yo;
int *Y;

int oYstride = 4;
int Ystride = 4;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    const size_t num_elements = total_size / sizeof(unsigned int);
    
    Yo_data = (unsigned int*)calloc(num_elements, sizeof(unsigned int));
    Y_data = (int*)calloc(num_elements, sizeof(int));
    
    if (!Yo_data || !Y_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < num_elements; idx++) {
        Yo_data[idx] = (unsigned int)(idx * 31 + 7);
    }
    
    Yo = Yo_data;
    Y = Y_data;
}

// Reset pointers to initial state before calling loop
void reset_vars() {
    Yo = Yo_data;
    Y = Y_data;
}