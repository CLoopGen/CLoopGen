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

avl_node *pa[32];
unsigned char da[32];
int k;
avl_node *r;
avl_node *s;

#define DATA_SIZE (1 << 20)

static avl_node nodes[DATA_SIZE];

void init_vars() {
    for (int i = 0; i < DATA_SIZE; ++i) {
        nodes[i].avl_link[0] = (i * 2 + 1 < DATA_SIZE) ? &nodes[i * 2 + 1] : NULL;
        nodes[i].avl_link[1] = (i * 2 + 2 < DATA_SIZE) ? &nodes[i * 2 + 2] : NULL;
        nodes[i].avl_data = NULL;
        nodes[i].avl_balance = 0;
    }

    k = 0;
    r = &nodes[0];
    s = NULL;

    for (int i = 0; i < 32; ++i) {
        pa[i] = NULL;
        da[i] = 0;
    }
}