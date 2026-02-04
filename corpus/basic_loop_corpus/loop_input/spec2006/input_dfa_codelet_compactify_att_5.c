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
int k;
int *map;

#define INDEX_COUNT (1 << 20)

static state_t *generated_states;
static attrib_t *generated_indexes;
static int *generated_map;

void init_vars() {
    generated_states = calloc(1024, sizeof(state_t));
    generated_indexes = calloc(INDEX_COUNT, sizeof(attrib_t));
    generated_map = calloc(INDEX_COUNT, sizeof(int));

    pdfa = malloc(sizeof(dfa_t));
    memset(pdfa->name, 0, 80);
    strcpy(pdfa->name, "test_dfa");
    pdfa->pre_rotated = 0;
    pdfa->states = generated_states;
    pdfa->max_states = 1024;
    pdfa->last_state = 1023;
    pdfa->indexes = generated_indexes;
    pdfa->max_indexes = INDEX_COUNT;
    pdfa->last_index = INDEX_COUNT - 1;

    map = generated_map;

    for (int i = 0; i < INDEX_COUNT; i++) {
        generated_map[i] = (i * 78901 + 12345) % INDEX_COUNT;
        generated_indexes[i].val = i;
        generated_indexes[i].next = (i * 101 + 4567) % INDEX_COUNT;
    }
}