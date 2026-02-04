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
    for (i = 0; params[i].key != ((void *)0) && i < 100; i += 2) {
        volatile size_t size = params[i].data_size;
        if (size > 0) {
            size *= 3;
            size /= 2;
        }
        params[i].return_size = size;
    }
}
