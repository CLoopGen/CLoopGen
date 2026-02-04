#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB

unsigned short *p;
unsigned short *q;
int i;

static unsigned short *p_storage;
static unsigned short *q_storage;

void init_vars() {
    size_t num_elements = DATA_SIZE / sizeof(unsigned short);
    
    p_storage = (unsigned short *)aligned_alloc(32, num_elements * sizeof(unsigned short));
    q_storage = (unsigned short *)aligned_alloc(32, num_elements * sizeof(unsigned short));

    if (!p_storage || !q_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        p_storage[idx] = (unsigned short)(idx & 0xFFFF);
        q_storage[idx] = 0;
    }

    p = &p_storage[num_elements - 1]; 
    q = q_storage;
}