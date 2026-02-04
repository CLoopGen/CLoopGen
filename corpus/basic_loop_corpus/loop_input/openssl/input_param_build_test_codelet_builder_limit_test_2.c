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

static char **keys;
static OSSL_PARAM *params_internal;
OSSL_PARAM *params;
int i;

void init_vars() {
    const size_t num_elements = 50000;
    params_internal = calloc(num_elements + 1, sizeof(OSSL_PARAM));
    keys = malloc(num_elements * sizeof(char*));

    for (size_t idx = 0; idx < num_elements; idx++) {
        keys[idx] = malloc(16);
        sprintf(keys[idx], "key%zu", idx);
        params_internal[idx].key = keys[idx];
        params_internal[idx].data_type = idx % 4;
        params_internal[idx].data = NULL;
        params_internal[idx].data_size = idx * 16;
        params_internal[idx].return_size = 0;
    }
    params_internal[num_elements].key = NULL;

    params = params_internal;
    i = 0;
}