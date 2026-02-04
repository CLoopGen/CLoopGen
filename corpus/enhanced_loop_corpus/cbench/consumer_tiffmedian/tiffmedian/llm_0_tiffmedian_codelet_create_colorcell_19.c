#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int num_ents;
    int entries[256][2];
} C_cell;

extern int i;
extern C_cell *ptr;
extern int next_n;
extern int tmp;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n1, i1;
    for (n1 = ptr->num_ents - 1; n1 > 0; n1 = next_n) {
        next_n = 0;
        for (i1 = 0; i1 < n1; ++i1) {
            if (ptr->entries[i1][1] > ptr->entries[i1 + 1][1]) {
                tmp = ptr->entries[i1][0];
                ptr->entries[i1][0] = ptr->entries[i1 + 1][0];
                ptr->entries[i1 + 1][0] = tmp;
                tmp = ptr->entries[i1][1];
                ptr->entries[i1][1] = ptr->entries[i1 + 1][1];
                ptr->entries[i1 + 1][1] = tmp;
                next_n = i1;
            }
        }
    }
}
