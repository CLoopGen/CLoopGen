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
    da[k] = 0;
    pa[k++] = r;
    s = r->avl_link[0];
    if (s->avl_link[0] != ((void *)0)) {
        goto continue_loop;
    }
    return;

continue_loop:
    r = s;
    goto loop; 

loop:
    da[k] = 0;
    pa[k++] = r;
    s = r->avl_link[0];
    if (s->avl_link[0] == ((void *)0))
        return;
    r = s;
    goto loop;
}
