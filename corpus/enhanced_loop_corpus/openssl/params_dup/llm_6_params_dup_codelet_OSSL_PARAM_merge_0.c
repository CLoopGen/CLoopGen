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



void loop() {
    size_t idx = 0;
    OSSL_PARAM *current = p1;
    while (current->key != ((void *)0) && idx < 128) {
        list1[idx] = current;
        idx++;
        current++;
    }
    list1_sz = idx;
}
