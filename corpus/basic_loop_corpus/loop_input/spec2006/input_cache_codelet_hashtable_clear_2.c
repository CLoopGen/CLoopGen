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
    table = (Hashtable *)calloc(1, sizeof(Hashtable));
    
    // Aim for ~64-128MB of Hashnode data to target 0.01s runtime on modern CPU
    table->num_nodes = 2097152; // ~2M nodes => ~128MB assuming 64-byte per node
    
    table->all_nodes = (Hashnode *)calloc(table->num_nodes, sizeof(Hashnode));
    if (!table->all_nodes) {
        fprintf(stderr, "Failed to allocate all_nodes\n");
        exit(1);
    }
    
    table->hashtablesize = 65536;
    table->hashtable = (Hashnode **)calloc(table->hashtablesize, sizeof(Hashnode *));
    if (!table->hashtable) {
        fprintf(stderr, "Failed to allocate hashtable\n");
        exit(1);
    }
    
    table->num_results = 1048576;
    table->all_results = (Read_result *)calloc(table->num_results, sizeof(Read_result));
    if (!table->all_results) {
        fprintf(stderr, "Failed to allocate all_results\n");
        exit(1);
    }
    
    table->free_node = 0;
    table->free_result = 0;
}