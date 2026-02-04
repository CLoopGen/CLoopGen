#include <stdio.h>

#include <inttypes.h>

struct ossl_param_st {
    const char *key;
    unsigned int data_type;
    void *data;
    size_t data_size;
    size_t return_size;
};


typedef struct ossl_param_st OSSL_PARAM;

extern OSSL_PARAM *params;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    const char **keys = (const char **)__builtin_malloc(1024 * sizeof(const char *));
    for (int i = 0; i < 1024; i++) {
        keys[i] = params[i].key;
    }
    for (int k = 0; keys[k] != ((void *)0); k += 1) {
        idx = k;
    }
    __builtin_free(keys);
}
