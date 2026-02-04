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

rb_node *pa[48];
unsigned char da[48];
int k;
rb_node *r;
rb_node *s;

#define NODE_COUNT (1 << 20)

static rb_node nodes[NODE_COUNT];

void init_vars() {
    for (int i = 0; i < NODE_COUNT; i++) {
        nodes[i].rb_link[0] = (i * 2 + 1 < NODE_COUNT) ? &nodes[i * 2 + 1] : NULL;
        nodes[i].rb_link[1] = (i * 2 + 2 < NODE_COUNT) ? &nodes[i * 2 + 2] : NULL;
        nodes[i].rb_data = NULL;
        nodes[i].rb_color = 1;
    }

    k = 0;
    r = &nodes[0];
    s = NULL;

    for (int i = 0; i < 48; i++) {
        pa[i] = NULL;
        da[i] = 0;
    }
}