#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct cse_reg_info {
    struct cse_reg_info *hash_next;
    struct cse_reg_info *next;
    unsigned int regno;
    int reg_qty;
    int reg_tick;
    int reg_in_table;
};

static struct cse_reg_info *hash_head_storage;
static struct cse_reg_info node_pool[100000];
static unsigned int regno_storage;

struct cse_reg_info **hash_head = &hash_head_storage;
unsigned int regno = 0;
struct cse_reg_info *p = NULL;

void init_vars() {
    const int num_nodes = 100000;
    regno = num_nodes / 2; 

    for (int i = 0; i < num_nodes; ++i) {
        node_pool[i].regno = i;
        node_pool[i].reg_qty = i * 2;
        node_pool[i].reg_tick = i * 3;
        node_pool[i].reg_in_table = i * 4;
        node_pool[i].next = (i + 1 < num_nodes) ? &node_pool[i + 1] : NULL;
        node_pool[i].hash_next = (i + 1 < num_nodes) ? &node_pool[i + 1] : NULL;
    }

    hash_head_storage = &node_pool[0];
    p = NULL;
}