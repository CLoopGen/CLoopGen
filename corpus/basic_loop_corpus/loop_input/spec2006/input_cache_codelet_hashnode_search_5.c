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

Read_result *result;
Hashnode *node;
unsigned int search_for1 = 12345;
unsigned int search_for2 = 512;

#define DATA_SIZE (1 << 20)
static Read_result result_pool[DATA_SIZE];
static Hashnode node_storage;

void init_vars() {
    node = &node_storage;
    node->results = result_pool;
    node->next = NULL;

    for (int i = 0; i < DATA_SIZE - 1; i++) {
        result_pool[i].data1 = i;
        result_pool[i].data2 = i * 3;
        result_pool[i].next = &result_pool[i + 1];
    }
    result_pool[DATA_SIZE - 1].data1 = search_for1;
    result_pool[DATA_SIZE - 1].data2 = search_for2 | (search_for1 * 3);
    result_pool[DATA_SIZE - 1].next = NULL;
}