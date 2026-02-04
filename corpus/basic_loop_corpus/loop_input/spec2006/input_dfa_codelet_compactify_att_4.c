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
int last;
int save_last;
int *map;
int *search_first;
int *search_next;

#define DATA_SIZE_MB 64
#define MAX_INDEXES (DATA_SIZE_MB * (1 << 16) / sizeof(attrib_t))

static state_t *init_states;
static attrib_t *init_indexes;
static int *init_map;
static int *init_search_first;
static int *init_search_next;

void init_vars() {
    pdfa = (dfa_t*)calloc(1, sizeof(dfa_t));
    if (!pdfa) exit(1);

    init_states = (state_t*)calloc(MAX_INDEXES, sizeof(state_t));
    if (!init_states) exit(1);
    pdfa->states = init_states;
    pdfa->max_states = MAX_INDEXES;
    pdfa->last_state = 0;

    init_indexes = (attrib_t*)calloc(MAX_INDEXES + 1, sizeof(attrib_t));
    if (!init_indexes) exit(1);
    pdfa->indexes = init_indexes;
    pdfa->max_indexes = MAX_INDEXES;
    pdfa->last_index = MAX_INDEXES - 1;

    for (int i = 1; i <= MAX_INDEXES; i++) {
        pdfa->indexes[i].val = rand() % (MAX_INDEXES / 4);
        pdfa->indexes[i].next = rand() % MAX_INDEXES;
    }

    init_map = (int*)calloc(MAX_INDEXES + 1, sizeof(int));
    if (!init_map) exit(1);
    map = init_map;

    init_search_first = (int*)calloc(MAX_INDEXES / 4, sizeof(int));
    if (!init_search_first) exit(1);
    search_first = init_search_first;

    init_search_next = (int*)calloc(MAX_INDEXES + 1, sizeof(int));
    if (!init_search_next) exit(1);
    search_next = init_search_next;

    k = 0;
    last = 1;
    save_last = MAX_INDEXES / 2;
}