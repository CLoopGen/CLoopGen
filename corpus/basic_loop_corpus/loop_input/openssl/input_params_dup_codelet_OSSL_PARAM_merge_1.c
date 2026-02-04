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

static OSSL_PARAM param_array[256];
static OSSL_PARAM* list2_data[129];

OSSL_PARAM *p2 = param_array;
OSSL_PARAM **list2 = list2_data;
OSSL_PARAM *p;
size_t list2_sz = 0;

void init_vars() {
    for (int i = 0; i < 255; i++) {
        static char keys[255][16];
        snprintf(keys[i], sizeof(keys[i]), "key%d", i);
        param_array[i].key = keys[i];
        param_array[i].data_type = 1;
        param_array[i].data = malloc(1024);
        param_array[i].data_size = 1024;
        param_array[i].return_size = 0;
    }
    param_array[255].key = NULL;
    param_array[255].data_type = 0;
    param_array[255].data = NULL;
    param_array[255].data_size = 0;
    param_array[255].return_size = 0;
}