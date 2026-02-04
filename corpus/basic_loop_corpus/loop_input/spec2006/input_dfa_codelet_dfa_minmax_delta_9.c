#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct state {
    int att;
    int next[4];
} state_t;

typedef struct attrib {
    int val;
    int next;
} attrib_t;

typedef struct dfa {
    char name[80];
    int pre_rotated;
    state_t *states;
    int max_states;
    int last_state;
    attrib_t *indexes;
    int max_indexes;
    int last_index;
} dfa_t;

dfa_t *pdfa;
int next_index;
int isMin;
int ret;
int i;
int j;

static state_t *allocated_states;
static attrib_t *allocated_indexes;

void init_vars() {
    // Allocate states: aim for ~1MB of state data: each state is (4 * sizeof(int) + padding) = 20 bytes typically
    // Use ~50000 states to get around 1MB
    const int num_states = 50000;
    allocated_states = calloc(num_states, sizeof(state_t));
    if (!allocated_states) exit(1);

    // Initialize states with valid transitions within bounds
    for (int idx = 0; idx < num_states; idx++) {
        allocated_states[idx].att = idx;
        for (int k = 0; k < 4; k++) {
            // Random-like but deterministic: some zero, some valid non-zero
            if ((idx + k) % 7 == 0) {
                allocated_states[idx].next[k] = 0;
            } else {
                allocated_states[idx].next[k] = (idx + 13 + k) % num_states;
            }
        }
    }

    const int num_indexes = 10000;
    allocated_indexes = calloc(num_indexes, sizeof(attrib_t));
    if (!allocated_indexes) exit(1);
    for (int idx = 0; idx < num_indexes; idx++) {
        allocated_indexes[idx].val = idx * 2;
        allocated_indexes[idx].next = (idx + 1) % num_indexes;
    }

    // Allocate and initialize dfa structure
    pdfa = malloc(sizeof(dfa_t));
    if (!pdfa) exit(1);
    strcpy(pdfa->name, "test_dfa");
    pdfa->pre_rotated = 0;
    pdfa->states = allocated_states;
    pdfa->max_states = num_states;
    pdfa->last_state = num_states - 1;
    pdfa->indexes = allocated_indexes;
    pdfa->max_indexes = num_indexes;
    pdfa->last_index = num_indexes - 1;

    // Initialize other external variables
    next_index = 1;  // so condition (j == next_index || next_index < 0) triggers for j=1
    isMin = 0;       // set to 0 or 1; doesn't affect memory safety
    ret = isMin ? __INT_MAX__ : 0;  // proper initial value for min/max logic

    // Ensure loop bounds are safe: i from 0 to last_state, j from 0 to 3
    // Our allocations ensure that last_state = num_states-1, and next[4] is always valid
}

// Cleanup function to avoid memory leaks in long-running contexts
void cleanup_vars() {
    free(allocated_states);
    free(allocated_indexes);
    free(pdfa);
}