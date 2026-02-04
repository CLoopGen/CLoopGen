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
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating j from 0 to 3 in order, access indices with a stride of 2 (mod 4) to create non-consecutive access.
    int stride = 2;
    for (i = 0; i <= pdfa->last_state; i++) {
        for (j = 0; j < 4; j++) {
            int idx = (j * stride) % 4; // Strided index access: 0, 2, 0, 2 -> use mod to stay in range
            if (idx == next_index || next_index < 0) {
                int next = pdfa->states[i].next[idx];
                if (!next)
                    continue;
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
