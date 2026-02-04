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

extern  OSSL_PARAM *p1;
extern  OSSL_PARAM *list1[129];
extern  OSSL_PARAM *p;
extern size_t list1_sz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 1; i++) {
        for (p = p1; p->key != ((void *)0) && list1_sz < 128; p++)
            list1[list1_sz++] = p;
    }
}
