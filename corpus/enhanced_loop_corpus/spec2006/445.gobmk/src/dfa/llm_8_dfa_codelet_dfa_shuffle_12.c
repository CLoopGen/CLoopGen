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
extern int *state_to;
extern int *state_from;
extern int *queue1;
extern int *queue2;
extern int next_new_state;
extern int q1p;
extern int q2p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int base_state;
for (i = 0; i < q1p; i++) {
    base_state = queue1[i];
    for (j = 0; j < 4; j += 2) {
        int n1 = pdfa->states[base_state].next[j];
        if (n1 && !state_to[n1]) {
            state_to[n1] = next_new_state;
            state_from[next_new_state] = n1;
            queue2[q2p++] = n1;
            next_new_state++;
        }
        if (j + 1 < 4) {
            int n2 = pdfa->states[base_state].next[j + 1];
            if (n2 && !state_to[n2]) {
                state_to[n2] = next_new_state;
                state_from[next_new_state] = n2;
                queue2[q2p++] = n2;
                next_new_state++;
            }
        }
    }
}
}
