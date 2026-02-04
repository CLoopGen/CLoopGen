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
        for (int k = 0; k < 4; k += 2) {
            int n = pdfa->states[queue1[i]].next[k];
            if (n && !state_to[n]) {
                state_to[n] = next_new_state;
                state_from[next_new_state] = n;
                next_new_state++;
                queue2[q2p++] = n;
            }
            if (k + 1 < 4) {
                int m = pdfa->states[queue1[i]].next[k + 1];
                if (m && !state_to[m]) {
                    state_to[m] = next_new_state;
                    state_from[next_new_state] = m;
                    next_new_state++;
                    queue2[q2p++] = m;
                }
            }
        }
    }
}
