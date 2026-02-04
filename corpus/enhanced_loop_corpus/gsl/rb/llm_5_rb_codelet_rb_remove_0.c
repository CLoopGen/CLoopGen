#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_bst_rb_node {
    struct gsl_bst_rb_node *rb_link[2];
    void *rb_data;
    unsigned char rb_color;
};


typedef struct gsl_bst_rb_node rb_node;

extern rb_node *pa[48];
extern unsigned char da[48];
extern int k;
extern rb_node *r;
extern rb_node *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        da[k] = 0;
        pa[k] = r;
        k += 1;
        s = r->rb_link[0];
        r = s;
        if (s->rb_link[0] == ((void *)0)) {
            break;
        }
        if (((uintptr_t)s) & 1) {
            continue;
        }
        r = r->rb_link[0];
        da[k] = 1;
        pa[k++] = r;
        if (r->rb_link[0] == ((void *)0))
            break;
    }
}
