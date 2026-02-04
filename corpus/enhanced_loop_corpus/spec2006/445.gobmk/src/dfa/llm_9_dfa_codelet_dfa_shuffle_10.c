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
extern struct state *old_states;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= pdfa->last_state; i += 2) {
    for (j = 0; j < 4; j++) {
        if (i <= pdfa->last_state) {
            old_states[i].next[j] = pdfa->states[i].next[j];
            old_states[i].att = pdfa->states[i].att;
        }
        if (i + 1 <= pdfa->last_state) {
            old_states[i+1].next[j] = pdfa->states[i+1].next[j];
            old_states[i+1].att = pdfa->states[i+1].att;
        }
    }
}
}
