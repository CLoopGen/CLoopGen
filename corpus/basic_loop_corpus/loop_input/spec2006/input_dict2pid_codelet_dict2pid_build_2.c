#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;
typedef unsigned int uint32;
typedef float float32;
typedef double float64;

typedef union anytype_s {
    void *ptr;
    int32 int32;
    uint32 uint32;
    float32 float32;
    float64 float64;
} anytype_t;

typedef struct gnode_s {
    anytype_t data;
    struct gnode_s *next;
} gnode_t;

typedef gnode_t *glist_t;

typedef short int16;
typedef int16 s3senid_t;

typedef struct hash_entry_s {
    const char *key;
    int32 len;
    int32 val;
    struct hash_entry_s *next;
} hash_entry_t;

glist_t g = NULL;
gnode_t *gn = NULL;
s3senid_t *sen = NULL;
hash_entry_t *he = NULL;
int32 *cslen = NULL;
int32 i = 0;
int32 n = 0;

#define NUM_NODES 100000
#define MAX_SEN_LENGTH 256

static s3senid_t sen_data[NUM_NODES][MAX_SEN_LENGTH];
static hash_entry_t hash_entries[NUM_NODES];
static gnode_t gnodes[NUM_NODES];

void init_vars() {
    // Allocate cslen with sufficient size
    cslen = (int32*)calloc(NUM_NODES, sizeof(int32));
    if (!cslen) exit(1);

    // Initialize all nodes
    for (int idx = 0; idx < NUM_NODES; idx++) {
        // Fill sen_data with non-negative values ending with -1
        int len = (idx % (MAX_SEN_LENGTH - 1)) + 1; // Length from 1 to 255
        for (int j = 0; j < len; j++) {
            sen_data[idx][j] = (s3senid_t)(j & 0x7FFF); // Small non-negative values
        }
        sen_data[idx][len] = -1; // Terminate the sequence

        // Initialize hash entry
        hash_entries[idx].key = (const char*)sen_data[idx];
        hash_entries[idx].len = len + 1;
        hash_entries[idx].val = idx;
        hash_entries[idx].next = NULL;

        // Initialize gnode
        gnodes[idx].data.ptr = &hash_entries[idx];
        gnodes[idx].next = (idx == NUM_NODES - 1) ? NULL : &gnodes[idx + 1];
    }

    // Set head of list
    g = &gnodes[0];
    n = 0;
}