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
extern int next_index;
extern int isMin;
extern int ret;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= pdfa->last_state; i++) {
    int next = 0;
    if (next_index >= 0 && next_index < 4) {
        next = pdfa->states[i].next[next_index];
        if (next) {
            if (isMin) {
                if (ret > next - i)
                    ret = next - i;
            } else {
                if (ret < next - i)
                    ret = next - i;
            }
        }
    } else {
        for (j = 0; j < 4; j++) {
            next = pdfa->states[i].next[j];
            if (next) {
                if (isMin) {
                    if (ret > next - i)
                        ret = next - i;
                } else {
                    if (ret < next - i)
                        ret = next - i;
                }
            }
        }
    }
}
}
