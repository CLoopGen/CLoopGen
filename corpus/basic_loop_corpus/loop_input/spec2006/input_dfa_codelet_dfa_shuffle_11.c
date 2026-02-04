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
state_t *old_states;
int *state_to;
int *state_from;
int i;
int j;

void init_vars() {
    const int data_size = 1 << 20; // ~4MB of state data, scale as needed

    pdfa = (dfa_t*)calloc(1, sizeof(dfa_t));
    if (!pdfa) exit(1);

    pdfa->max_states = data_size;
    pdfa->last_state = data_size - 1;
    pdfa->states = (state_t*)calloc(pdfa->max_states, sizeof(state_t));
    if (!pdfa->states) exit(1);

    old_states = (state_t*)calloc(data_size * 2, sizeof(state_t));
    if (!old_states) exit(1);
    for (int idx = 0; idx < data_size * 2; idx++) {
        old_states[idx].att = idx % 100;
        for (int k = 0; k < 4; k++) {
            old_states[idx].next[k] = (idx + k) % (data_size * 2);
        }
    }

    state_to = (int*)malloc((data_size * 2) * sizeof(int));
    if (!state_to) exit(1);
    for (int idx = 0; idx < data_size * 2; idx++) {
        state_to[idx] = (idx * 7) % (data_size * 2);
    }

    state_from = (int*)malloc(data_size * sizeof(int));
    if (!state_from) exit(1);
    for (int idx = 0; idx < data_size; idx++) {
        state_from[idx] = (idx + 100) % (data_size * 2);
    }
}
