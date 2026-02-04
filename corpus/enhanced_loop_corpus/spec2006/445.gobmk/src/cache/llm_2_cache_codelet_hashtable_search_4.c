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



void loop() {
    // Variant 1: Strided memory access pattern
    // Instead of iterating through hashval elements consecutively (i = 1, 2, ...),
    // we use a stride of 2 and handle remaining elements in a second pass if needed.
    // This changes the access pattern to strided within bounds.

    int stride = 2;
    int total_elements = (64 / (8 * sizeof(long)));
    for (node = table->hashtable[bucket]; node != ((void *)0); node = node->next) {
        if (node->key.hashval[0] != hd->hashval[0])
            continue;

        int matched = 1;
        // First pass: strided access
        for (i = stride; i < total_elements; i += stride) {
            if (node->key.hashval[i] != hd->hashval[i]) {
                stats.hash_collisions++;
                matched = 0;
                break;
            }
        }
        if (!matched)
            continue;

        // Second pass: fill-in for non-strided indices (i=1,3,... if stride=2)
        matched = 1;
        for (i = 1; i < stride && i < total_elements; i++) {
            if (node->key.hashval[i] != hd->hashval[i]) {
                stats.hash_collisions++;
                matched = 0;
                break;
            }
        }

        if (matched) {
            i = total_elements; // signal successful match
            break;
        }
    }
}
