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
    OSSL_PARAM *access_pattern[128];
    size_t temp_idx = 0;
    for (p = p1; p->key != ((void *)0) && temp_idx < 128; p++)
        access_pattern[temp_idx++] = p;
    for (size_t i = 0; i < temp_idx; i++)
        list1[list1_sz++] = access_pattern[i];
}
