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

extern OSSL_PARAM *param;
extern OSSL_PARAM *p;
extern int p_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OSSL_PARAM *temp = param;
    p_num = 0;
    for (; temp != ((void *)0) && temp->key != ((void *)0); temp++) {
        p_num++;
        p = temp;
    }
}
