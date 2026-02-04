#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float noise_table[4116];
int i;
uint64_t random_seed = 123456789;
float delta = 0.0001f;

void init_vars() {
    // Initialize any required variables if necessary
    // All externs are already at file scope and initialized as needed
}