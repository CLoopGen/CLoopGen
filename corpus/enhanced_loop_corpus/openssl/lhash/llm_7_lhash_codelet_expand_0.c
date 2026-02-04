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
    unsigned long local_hash;
    OPENSSL_LH_NODE *next_ptr;
    for (np = *n1; np != ((void *)0);) {
        local_hash = np->hash;
        next_ptr = np->next;
        if ((local_hash % nni) != p) {
            *n1 = next_ptr;
            np->next = *n2;
            *n2 = np;
        } else {
            n1 = &(np->next);
        }
        np = next_ptr;
    }
}
