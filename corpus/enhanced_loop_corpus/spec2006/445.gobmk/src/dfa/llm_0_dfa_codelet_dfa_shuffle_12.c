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
    for (i = 0; i < q1p; i++) {
        int base = queue1[i];
        int n0 = pdfa->states[base].next[0];
        if (n0 && !state_to[n0]) {
            state_to[n0] = next_new_state;
            state_from[next_new_state] = n0;
            next_new_state++;
            queue2[q2p++] = n0;
        }
        int n1 = pdfa->states[base].next[1];
        if (n1 && !state_to[n1]) {
            state_to[n1] = next_new_state;
            state_from[next_new_state] = n1;
            next_new_state++;
            queue2[q2p++] = n1;
        }
        int n2 = pdfa->states[base].next[2];
        if (n2 && !state_to[n2]) {
            state_to[n2] = next_new_state;
            state_from[next_new_state] = n2;
            next_new_state++;
            queue2[q2p++] = n2;
        }
        int n3 = pdfa->states[base].next[3];
        if (n3 && !state_to[n3]) {
            state_to[n3] = next_new_state;
            state_from[next_new_state] = n3;
            next_new_state++;
            queue2[q2p++] = n3;
        }
    }
}
