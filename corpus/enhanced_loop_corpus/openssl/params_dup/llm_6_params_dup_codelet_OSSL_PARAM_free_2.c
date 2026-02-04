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
extern OSSL_PARAM *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OSSL_PARAM *temp = params;
    while (1) {
        if (temp->key == ((void *)0)) break;
        temp++;
    }
    p = temp;
}
