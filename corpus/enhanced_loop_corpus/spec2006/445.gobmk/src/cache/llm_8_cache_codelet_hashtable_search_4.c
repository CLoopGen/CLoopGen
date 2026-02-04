#include <stdio.h>

#include <inttypes.h>

struct stats_data {
    int nodes;
    int position_entered;
    int position_hits;
    int read_result_entered;
    int read_result_hits;
    int hash_collisions;
};


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

extern struct stats_data stats;
extern Hashtable *table;
extern Hash_data *hd;
extern Hashnode *node;
extern int bucket;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    node = table->hashtable[bucket];
    while (node != ((void *)0)) {
        if (node->key.hashval[0] == hd->hashval[0]) {
            int match = 1;
            for (i = 1; i < (64 / (8 * sizeof(long))); i++) {
                if (node->key.hashval[i] != hd->hashval[i]) {
                    stats.hash_collisions++;
                    match = 0;
                    break;
                }
            }
            if (match) break;
        }
        node = node->next;
    }
}
