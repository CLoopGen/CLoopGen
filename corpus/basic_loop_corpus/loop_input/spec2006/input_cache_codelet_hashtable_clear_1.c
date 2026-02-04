#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

typedef struct read_result_t {
    unsigned int data1;
    unsigned int data2;
    struct read_result_t *next;
} Read_result;

typedef struct hashnode_t {
    Hash_data key;
    Read_result *results;
    struct hashnode_t *next;
} Hashnode;

typedef struct hashtable {
    int hashtablesize;
    Hashnode **hashtable;
    int num_nodes;
    Hashnode *all_nodes;
    int free_node;
    int num_results;
    Read_result *all_results;
    int free_result;
} Hashtable;

Hashtable *table;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of Read_result data
    const int num_results = data_size / sizeof(Read_result);

    table = (Hashtable*)calloc(1, sizeof(Hashtable));
    if (!table) exit(1);

    table->all_results = (Read_result*)calloc(num_results, sizeof(Read_result));
    if (!table->all_results) exit(1);

    for (int j = 0; j < num_results; j++) {
        table->all_results[j].data1 = j;
        table->all_results[j].data2 = j + 1;
        table->all_results[j].next = NULL;
    }

    table->num_results = num_results;
}