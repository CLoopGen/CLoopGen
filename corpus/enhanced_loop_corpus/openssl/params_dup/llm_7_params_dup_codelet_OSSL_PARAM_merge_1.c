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

extern  OSSL_PARAM *p2;
extern  OSSL_PARAM *list2[129];
extern  OSSL_PARAM *p;
extern size_t list2_sz;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t local_size = list2_sz;
    for (p = p2; p->key != ((void *)0) && local_size < 128; p++) {
        list2[local_size++] = p;
    }
    list2_sz = local_size;
}
