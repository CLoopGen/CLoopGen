#include <stdio.h>

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

extern Hashtable *table;
extern int bucket;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int double_size = table->hashtablesize * 2;
    for (bucket = 0; bucket < double_size; ++bucket) {
        int index = bucket >> 1;
        if (index < table->hashtablesize) {
            table->hashtable[index] = ((void *)0);
        }
    }
}
