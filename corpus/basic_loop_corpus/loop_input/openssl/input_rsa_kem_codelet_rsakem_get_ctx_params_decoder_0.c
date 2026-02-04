#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct ossl_param_st {
    const char *key;
    unsigned int data_type;
    void *data;
    size_t data_size;
    size_t return_size;
};

typedef struct ossl_param_st OSSL_PARAM;

static OSSL_PARAM param_array[512];
OSSL_PARAM *p = param_array;
char *s = NULL;

void init_vars() {
    for (int i = 0; i < 511; i++) {
        char *key_str = malloc(16);
        sprintf(key_str, "key%d", i);
        param_array[i].key = key_str;
        param_array[i].data_type = i % 3;
        param_array[i].data = malloc(32);
        param_array[i].data_size = 32;
        param_array[i].return_size = 0;
    }
    param_array[511].key = NULL;
    param_array[511].data_type = 0;
    param_array[511].data = NULL;
    param_array[511].data_size = 0;
    param_array[511].return_size = 0;
}