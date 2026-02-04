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
    int j;
    for (i = 0; params[i].key != ((void *)0); i++) {
        j = i; // Introduce loop-carried WAW dependency: j is overwritten each iteration
    }
    i = j; // Use final value of j, creating a dependency from loop body to post-loop use
}
