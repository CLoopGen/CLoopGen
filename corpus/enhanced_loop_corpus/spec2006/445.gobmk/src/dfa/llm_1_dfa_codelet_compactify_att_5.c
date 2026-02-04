#include <stdio.h>

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

extern dfa_t *pdfa;
extern int k;
extern int *map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = pdfa->last_index; k >= 0; k--)
    pdfa->indexes[k].next = map[pdfa->indexes[k].next];

for (k = 0; k <= pdfa->last_index; k++)
    if (pdfa->indexes[k].next < 0)
        pdfa->indexes[k].next = 0;
}
