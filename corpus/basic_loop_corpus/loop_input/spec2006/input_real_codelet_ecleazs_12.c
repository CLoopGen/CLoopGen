#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short *xi;
int i;

static unsigned short *xi_storage;

void init_vars() {
    size_t num_elements = 268435456 / sizeof(unsigned short); // ~256MB of data
    xi_storage = (unsigned short *)calloc(num_elements, sizeof(unsigned short));
    if (!xi_storage) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    xi = xi_storage;
}

__attribute__((destructor))
static void cleanup() {
    free(xi_storage);
}