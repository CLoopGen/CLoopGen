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
state_t *old_states;
int i;
int j;

void init_vars() {
    pdfa = (dfa_t*)malloc(sizeof(dfa_t));
    memset(pdfa->name, 0, 80);
    strcpy(pdfa->name, "test_dfa");
    pdfa->pre_rotated = 0;
    pdfa->max_states = 65536;
    pdfa->last_state = 65535; // ensures about 1MB of data: 65536 * (sizeof(state_t)=20) ~ 1.3MB
    pdfa->max_indexes = 1024;
    pdfa->last_index = 512;

    pdfa->states = (state_t*)calloc(pdfa->max_states, sizeof(state_t));
    old_states = (state_t*)calloc(pdfa->max_states, sizeof(state_t));

    pdfa->indexes = (attrib_t*)calloc(pdfa->max_indexes, sizeof(attrib_t));

    for (int idx = 0; idx < pdfa->max_states; idx++) {
        pdfa->states[idx].att = idx * 789;
        for (int k = 0; k < 4; k++) {
            pdfa->states[idx].next[k] = (idx + k) * 123;
        }
    }

    for (int idx = 0; idx < pdfa->max_indexes; idx++) {
        pdfa->indexes[idx].val = idx * 456;
        pdfa->indexes[idx].next = idx * 789;
    }

    i = 0;
    j = 0;
}