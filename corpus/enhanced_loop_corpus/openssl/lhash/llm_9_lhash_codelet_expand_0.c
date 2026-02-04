#include <stdio.h>

#include <inttypes.h>

struct lhash_node_st {
    void *data;
    struct lhash_node_st *next;
    unsigned long hash;
};


typedef struct lhash_node_st OPENSSL_LH_NODE;

extern OPENSSL_LH_NODE **n1;
extern OPENSSL_LH_NODE **n2;
extern OPENSSL_LH_NODE *np;
extern unsigned int p;
extern unsigned int nni;
extern unsigned long hash;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int iter_count = 0;
    const unsigned int max_iters = 1000;
    for (np = *n1; np != ((void *)0) && iter_count < max_iters; iter_count++) {
        hash = np->hash;
        if ((hash % nni) == p) {
            n1 = &((*n1)->next);
        } else {
            *n1 = (*n1)->next;
            np->next = *n2;
            *n2 = np;
        }
        np = *n1;
    }
}
