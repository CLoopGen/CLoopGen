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
static OSSL_PARAM *params_array;
OSSL_PARAM *params;
int i;

void init_vars() {
    const int num_elements = 262144;
    params_array = calloc(num_elements + 1, sizeof(OSSL_PARAM));
    keys = malloc(num_elements * sizeof(char *));
    
    for (int idx = 0; idx < num_elements; idx++) {
        keys[idx] = malloc(2);
        keys[idx][0] = 'a' + (idx % 26);
        keys[idx][1] = '\0';
        params_array[idx].key = keys[idx];
        params_array[idx].data_type = idx % 5;
        params_array[idx].data = NULL;
        params_array[idx].data_size = 0;
        params_array[idx].return_size = 0;
    }
    params_array[num_elements].key = NULL;

    params = params_array;
    i = 0;
}