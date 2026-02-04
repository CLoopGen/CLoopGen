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
extern int last;
extern int save_last;
extern int *map;
extern int *search_first;
extern int *search_next;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Indirect memory access via pointer arithmetic and prefetching pattern
    attrib_t *index_base = pdfa->indexes;
    int *sfirst = search_first;
    int *snext = search_next;
    int *mp = map;

    for (k = 1; k <= save_last; k++) {
        attrib_t curr = index_base[k];
        int val = curr.val;
        int next_target = curr.next;
        int i = sfirst[val];

        if (i) {
            // Simulate strided traversal without while: use bounded for with early exit
            int prev = i;
            int reached = 0;
            for (int offset = 1; offset <= last; offset++) {
                if (index_base[i].next == next_target) {
                    reached = 1;
                    break;
                }
                int next_idx = snext[i];
                if (!next_idx) {
                    snext[prev] = ++last;
                    i = 0;
                    break;
                }
                prev = i;
                i = next_idx;
            }
            if (reached)
                mp[k] = i;
            else
                mp[k] = last;
        } else {
            sfirst[val] = ++last;
            mp[k] = last;
        }

        // Ensure state is copied only when mapping to new entry
        if (mp[k] == last)
            index_base[last] = curr;
    }
}
