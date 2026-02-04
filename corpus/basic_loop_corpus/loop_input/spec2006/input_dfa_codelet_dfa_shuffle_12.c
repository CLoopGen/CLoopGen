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
int *state_to;
int *state_from;
int *queue1;
int *queue2;
int next_new_state;
int q1p;
int q2p;
int i;
int j;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~64MB of state data
    const int num_states = data_size / sizeof(state_t);
    
    // Allocate and initialize pdfa
    pdfa = (dfa_t*)calloc(1, sizeof(dfa_t));
    strcpy(pdfa->name, "test_dfa");
    pdfa->pre_rotated = 0;
    pdfa->max_states = num_states;
    pdfa->last_state = num_states - 1;
    pdfa->max_indexes = 1000;
    pdfa->last_index = 999;

    // Allocate states
    pdfa->states = (state_t*)calloc(num_states, sizeof(state_t));
    
    // Initialize states: create a sparse graph with valid transitions
    for (int idx = 0; idx < num_states; idx++) {
        pdfa->states[idx].att = idx % 100;
        for (int k = 0; k < 4; k++) {
            // Create transition to another state with 30% probability
            if ((idx + k) % 7 == 0 && (idx + k) < num_states - 1) {
                pdfa->states[idx].next[k] = idx + k + 1;
            } else {
                pdfa->states[idx].next[k] = 0; // null transition
            }
        }
    }

    // Allocate auxiliary arrays
    state_to = (int*)calloc(num_states * 2, sizeof(int)); // extra space for new states
    state_from = (int*)calloc(num_states * 2, sizeof(int));
    
    // Initialize queue1 with some starting states (first few non-zero states)
    queue1 = (int*)malloc(num_states * sizeof(int));
    queue2 = (int*)malloc(num_states * sizeof(int));
    
    q1p = 0;
    for (int idx = 1; idx < num_states && q1p < 100000; idx += 11) { // sample states
        if (pdfa->states[idx].next[0] || pdfa->states[idx].next[1] ||
            pdfa->states[idx].next[2] || pdfa->states[idx].next[3]) {
            queue1[q1p++] = idx;
        }
    }
    
    q2p = 0;
    next_new_state = 1; // start assigning from 1
    
    // Ensure state_to entries for any potentially referenced states are zero-initialized
    for (int idx = 0; idx < num_states * 2; idx++) {
        state_to[idx] = 0;
        state_from[idx] = 0;
    }
}