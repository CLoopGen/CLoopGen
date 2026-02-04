#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct stats_data stats;
Hashtable *table;
Hash_data *hd;
Hashnode *node;
int bucket;
int i;

static Hashnode *g_hashnodes = NULL;
static Read_result *g_read_results = NULL;
static Hashnode **g_hashtable_buckets = NULL;

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024; // ~64 MB of node data
    const int num_nodes = total_data_size / (sizeof(Hashnode) + sizeof(Read_result));
    const int hashtablesize = num_nodes / 4;
    const int hash_width = (64 / (8 * sizeof(long)));

    int j;

    g_hashnodes = calloc(num_nodes, sizeof(Hashnode));
    g_read_results = calloc(num_nodes, sizeof(Read_result));
    g_hashtable_buckets = calloc(hashtablesize, sizeof(Hashnode*));

    if (!g_hashnodes || !g_read_results || !g_hashtable_buckets) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (j = 0; j < num_nodes; j++) {
        g_hashnodes[j].key.hashval[0] = j % 256;
        for (int k = 1; k < hash_width; k++) {
            ((Hashvalue*)&g_hashnodes[j].key)[k] = j ^ (k * 31);
        }
        g_hashnodes[j].results = &g_read_results[j];
        g_read_results[j].data1 = j * 2;
        g_read_results[j].data2 = j * 3;
        g_read_results[j].next = NULL;
        if (j > 0) {
            g_hashnodes[j-1].next = &g_hashnodes[j];
        }
    }
    g_hashnodes[num_nodes - 1].next = NULL;

    for (j = 0; j < hashtablesize; j++) {
        int idx = (j * 7) % num_nodes;
        g_hashtable_buckets[j] = &g_hashnodes[idx];
    }

    table = malloc(sizeof(Hashtable));
    if (!table) {
        fprintf(stderr, "Failed to allocate Hashtable\n");
        exit(1);
    }

    table->hashtablesize = hashtablesize;
    table->hashtable = g_hashtable_buckets;
    table->num_nodes = num_nodes;
    table->all_nodes = g_hashnodes;
    table->free_node = 0;
    table->num_results = num_nodes;
    table->all_results = g_read_results;
    table->free_result = 0;

    hd = malloc(sizeof(Hash_data));
    if (!hd) {
        fprintf(stderr, "Failed to allocate Hash_data\n");
        exit(1);
    }

    hd->hashval[0] = 100;
    for (int k = 1; k < hash_width; k++) {
        ((Hashvalue*)hd)[k] = 100 ^ (k * 31);
    }

    stats.nodes = 0;
    stats.position_entered = 0;
    stats.position_hits = 0;
    stats.read_result_entered = 0;
    stats.read_result_hits = 0;
    stats.hash_collisions = 0;

    bucket = 0;
    i = 0;

    node = table->hashtable[bucket];
}