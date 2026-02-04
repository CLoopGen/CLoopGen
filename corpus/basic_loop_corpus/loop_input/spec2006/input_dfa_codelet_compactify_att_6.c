#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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
int k;
int *map;

void init_vars() {
    const int data_size = 1 << 20; // ~4MB of state data, scales well

    pdfa = (dfa_t*)calloc(1, sizeof(dfa_t));
    if (!pdfa) exit(1);

    pdfa->max_states = data_size;
    pdfa->last_state = data_size - 1;
    pdfa->states = (state_t*)calloc(pdfa->max_states, sizeof(state_t));
    if (!pdfa->states) exit(1);

    map = (int*)calloc(data_size, sizeof(int));
    if (!map) exit(1);

    for (int i = 0; i < data_size; i++) {
        pdfa->states[i].att = i % 1000;
        map[i] = (i * 7) % 1000;
    }

    pdfa->max_indexes = 1000;
    pdfa->last_index = 999;
    pdfa->indexes = (attrib_t*)calloc(pdfa->max_indexes, sizeof(attrib_t));
    if (!pdfa->indexes) exit(1);
}