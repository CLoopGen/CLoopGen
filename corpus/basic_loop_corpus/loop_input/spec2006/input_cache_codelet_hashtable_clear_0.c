#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int bucket;

void init_vars() {
    // Allocate table structure
    table = (Hashtable*)calloc(1, sizeof(Hashtable));
    
    // Set hashtable size to ~64K buckets to ensure loop takes ~0.01s
    // Assuming modern CPU can do ~10M iterations per ms, we want ~100K iterations
    table->hashtablesize = 131072;  // 128K buckets
    
    // Allocate array of hashnode pointers
    table->hashtable = (Hashnode**)calloc(table->hashtablesize, sizeof(Hashnode*));
    
    // Initialize other fields
    table->num_nodes = 0;
    table->all_nodes = NULL;
    table->free_node = 0;
    table->num_results = 0;
    table->all_results = NULL;
    table->free_result = 0;
}