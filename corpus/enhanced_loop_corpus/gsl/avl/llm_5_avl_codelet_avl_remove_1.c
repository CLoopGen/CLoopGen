#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_bst_avl_node {
    struct gsl_bst_avl_node *avl_link[2];
    void *avl_data;
    signed char avl_balance;
};


typedef struct gsl_bst_avl_node avl_node;

extern avl_node *pa[32];
extern unsigned char da[32];
extern int k;
extern avl_node *r;
extern avl_node *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char first_iteration = 1;
    goto condition_check;

entry:
    da[k] = 0;
    pa[k++] = r;
    s = r->avl_link[0];
    if (first_iteration && s->avl_link[0] == ((void *)0))
        return;
    r = s;
    first_iteration = 0;

condition_check:
    if (first_iteration) goto entry;
    da[k] = 0;
    pa[k++] = r;
    s = r->avl_link[0];
    if (s->avl_link[0] == ((void *)0)) return;
    r = s;
    goto condition_check;
}
