#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

struct lhash_node_st {
    void *data;
    struct lhash_node_st *next;
    unsigned long hash;
};

typedef struct lhash_node_st OPENSSL_LH_NODE;

static OPENSSL_LH_NODE *node_array;
static OPENSSL_LH_NODE **n1_ptr;
static OPENSSL_LH_NODE **n2_ptr;

OPENSSL_LH_NODE **n1 = NULL;
OPENSSL_LH_NODE **n2 = NULL;
OPENSSL_LH_NODE *np = NULL;
unsigned int p = 0;
unsigned int nni = 16;
unsigned long hash = 0;

void init_vars() {
    const size_t data_size = 1024 * 128; // ~128KB of nodes
    const int num_nodes = data_size / sizeof(OPENSSL_LH_NODE);
    
    node_array = calloc(num_nodes, sizeof(OPENSSL_LH_NODE));
    if (!node_array) exit(1);
    
    n1_ptr = malloc(sizeof(OPENSSL_LH_NODE*));
    n2_ptr = malloc(sizeof(OPENSSL_LH_NODE*));
    if (!n1_ptr || !n2_ptr) exit(1);
    
    for (int i = 0; i < num_nodes - 1; i++) {
        node_array[i].data = malloc(16); // dummy data
        node_array[i].hash = (unsigned long)(i * 394857 + 12345);
        node_array[i].next = &node_array[i + 1];
    }
    node_array[num_nodes - 1].data = malloc(16);
    node_array[num_nodes - 1].hash = (unsigned long)((num_nodes - 1) * 394857 + 12345);
    node_array[num_nodes - 1].next = NULL;
    
    p = 7;
    nni = 16;
    
    *n1_ptr = &node_array[0];
    *n2_ptr = NULL;
    
    n1 = n1_ptr;
    n2 = n2_ptr;
}