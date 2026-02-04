#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct ossl_param_st {
    const char *key;
    unsigned int data_type;
    void *data;
    size_t data_size;
    size_t return_size;
};

typedef struct ossl_param_st OSSL_PARAM;

// Define external symbols
OSSL_PARAM *params = NULL;
OSSL_PARAM *p = NULL;

// Allocate sufficient memory to make the loop run ~0.01 seconds
// Assuming ~100k iterations takes ~0.01s on modern CPU, use ~512KB data
#define NUM_PARAMS 65536

static OSSL_PARAM param_array[NUM_PARAMS];

void init_vars() {
    // Initialize all params in the array
    for (size_t i = 0; i < NUM_PARAMS - 1; i++) {
        // Each key points to a valid string (non-null)
        param_array[i].key = "dummy";
        param_array[i].data_type = 1;
        param_array[i].data = NULL;
        param_array[i].data_size = 0;
        param_array[i].return_size = 0;
    }

    // Last element has NULL key to terminate loop
    param_array[NUM_PARAMS - 1].key = NULL;
    param_array[NUM_PARAMS - 1].data_type = 0;
    param_array[NUM_PARAMS - 1].data = NULL;
    param_array[NUM_PARAMS - 1].data_size = 0;
    param_array[NUM_PARAMS - 1].return_size = 0;

    // Initialize global pointers
    params = param_array;
    p = param_array; // Initial value of p is set but will be overwritten in loop
}