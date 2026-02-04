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



void loop() {
    for (i = 0; i < q1p; i++) {
        int base_index = queue1[i];
        state_t *current_state = &pdfa->states[base_index];
        int updates[4], count = 0;
        for (j = 0; j < 4; j++) {
            int n = current_state->next[j];
            if (n && !state_to[n]) {
                updates[count++] = n;
            }
        }
        for (j = 0; j < count; j++) {
            int n = updates[j];
            state_to[n] = next_new_state;
            state_from[next_new_state] = n;
            queue2[q2p++] = n;
            next_new_state++;
        }
    }
}
