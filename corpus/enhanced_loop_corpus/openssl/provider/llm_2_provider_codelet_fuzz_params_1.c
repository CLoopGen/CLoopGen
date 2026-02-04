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
    // Variant 1: Strided memory access with stride of 2
    for (p = param; p != ((void *)0) && p->key != ((void *)0); p += 2)
        p_num++;
}
