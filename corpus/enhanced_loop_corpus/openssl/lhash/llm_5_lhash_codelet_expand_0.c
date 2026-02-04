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
    for (np = *n1; np != ((void *)0); np = *n1) {
        hash = np->hash;
        unsigned int condition = (hash % nni) != p;
        if (condition) {
            OPENSSL_LH_NODE* temp = np->next;
            *n1 = temp;
            np->next = *n2;
            *n2 = np;
        } else {
            n1 = &((*n1)->next);
        }
    }
}
