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
    // Variant 2: Indirect memory access via index array
    // Use an explicitly defined index mapping (indirection) to access hashval elements.
    // This simulates a non-sequential, indirect memory access pattern,
    // which could model scenarios like sparse comparisons or reordered checks.

    int total_elements = (64 / (8 * sizeof(long)));
    int index_map[8]; // assume max 8 elements for 64-bit systems
    int num_indices = total_elements;

    // Define indirect order: even indices first, then odd (reverse order within groups)
    int j = 0;
    for (int ev = total_elements - 2; ev >= 0; ev -= 2)
        index_map[j++] = ev;
    for (int od = total_elements - 1; od >= 1; od -= 2)
        index_map[j++] = od;

    for (node = table->hashtable[bucket]; node != ((void *)0); node = node->next) {
        if (node->key.hashval[0] != hd->hashval[0])
            continue;

        int matched = 1;
        for (i = 0; i < num_indices; i++) {
            int idx = index_map[i];
            if (idx >= total_elements) continue;
            if (node->key.hashval[idx] != hd->hashval[idx]) {
                stats.hash_collisions++;
                matched = 0;
                break;
            }
        }

        if (matched) {
            i = total_elements; // indicate full match
            break;
        }
    }
}
