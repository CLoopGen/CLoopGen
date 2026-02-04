#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    uint_fast16_t ind;
    uint_fast32_t len;
    unsigned char *data;
} jpc_ppxstabent_t;

typedef struct {
    int numents;
    int maxents;
    jpc_ppxstabent_t **ents;
} jpc_ppxstab_t;

jpc_ppxstab_t *tab;
jpc_ppxstabent_t *ent;
int i;

static unsigned char *global_data_buffer;
static jpc_ppxstabent_t **ents_array;
static jpc_ppxstabent_t *ents_storage;

void init_vars() {
    // Allocate ~64MB of data to target ~0.01s runtime on modern CPUs
    const size_t total_data_size = 64 * 1024 * 1024;
    const int num_ents = 100000;  // Large enough for meaningful search, small enough for cache effects
    
    global_data_buffer = (unsigned char *)calloc(total_data_size, 1);
    if (!global_data_buffer) exit(1);
    
    ents_storage = (jpc_ppxstabent_t *)calloc(num_ents, sizeof(jpc_ppxstabent_t));
    if (!ents_storage) exit(1);
    
    ents_array = (jpc_ppxstabent_t **)calloc(num_ents, sizeof(jpc_ppxstabent_t *));
    if (!ents_array) exit(1);
    
    // Initialize entities with increasing indices to allow the loop's break condition to trigger
    for (int idx = 0; idx < num_ents; ++idx) {
        ents_storage[idx].ind = idx * 3;  // Increasing values: 0, 3, 6, ...
        ents_storage[idx].len = 1024;
        ents_storage[idx].data = global_data_buffer + (idx * 1024 % total_data_size);
        ents_array[idx] = &ents_storage[idx];
    }
    
    // Allocate and initialize the table
    tab = (jpc_ppxstab_t *)malloc(sizeof(jpc_ppxstab_t));
    if (!tab) exit(1);
    
    tab->numents = num_ents;
    tab->maxents = num_ents;
    tab->ents = ents_array;
    
    // Create target entity with ind value in the middle of the range to ensure early termination
    ent = (jpc_ppxstabent_t *)malloc(sizeof(jpc_ppxstabent_t));
    if (!ent) exit(1);
    
    ent->ind = num_ents * 3 / 2;  // Will cause loop to break around halfway
    ent->len = 2048;
    ent->data = global_data_buffer;
}