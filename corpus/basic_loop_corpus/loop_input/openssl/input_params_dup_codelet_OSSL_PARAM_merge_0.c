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

OSSL_PARAM *p1;
OSSL_PARAM *list1[129];
OSSL_PARAM *p;
size_t list1_sz;

static char keys_pool[1024 * 128]; // Large pool for key strings
static OSSL_PARAM param_array[1024];

void init_vars() {
    // Initialize the global variables

    // Setup key strings in the pool
    char *key_ptr = keys_pool;
    for (int i = 0; i < 1024; i++) {
        sprintf(key_ptr, "key%d", i);
        key_ptr += strlen(key_ptr) + 1;
    }

    // Initialize param_array
    for (int i = 0; i < 1024; i++) {
        param_array[i].key = keys_pool + (param_array[i].key ? 0 : (i * 32)); // Assign offset to key string
        if (i == 0) {
            // Ensure first key is valid
            param_array[i].key = keys_pool;
        }
        param_array[i].data_type = i % 5;
        param_array[i].data = &param_array[i].data_type; // Point to own field
        param_array[i].data_size = sizeof(unsigned int);
        param_array[i].return_size = 0;
    }

    // Null-terminate after some entries (simulate OSSL_PARAM_NULL)
    param_array[512].key = NULL;

    // Initialize p1 to point to beginning of param_array
    p1 = param_array;

    // Initialize list1 to null pointers
    for (int i = 0; i < 129; i++) {
        list1[i] = NULL;
    }

    // Initialize counters
    list1_sz = 0;
    p = NULL;
}