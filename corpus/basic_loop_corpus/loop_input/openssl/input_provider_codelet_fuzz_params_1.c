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

OSSL_PARAM *param = NULL;
OSSL_PARAM *p = NULL;
int p_num = 0;

void init_vars() {
    const int num_elements = 50000;
    param = malloc(num_elements * sizeof(OSSL_PARAM));
    if (!param) return;

    char **keys = malloc(num_elements * sizeof(char*));
    if (!keys) {
        free(param);
        return;
    }

    for (int i = 0; i < num_elements; i++) {
        keys[i] = malloc(16);
        if (keys[i]) {
            sprintf(keys[i], "key%d", i);
        }
        param[i].key = keys[i];
        param[i].data_type = i % 5;
        param[i].data = malloc(64);
        param[i].data_size = 64;
        param[i].return_size = 0;
    }

    param[num_elements - 1].key = NULL;

    p = param;
    p_num = 0;
}