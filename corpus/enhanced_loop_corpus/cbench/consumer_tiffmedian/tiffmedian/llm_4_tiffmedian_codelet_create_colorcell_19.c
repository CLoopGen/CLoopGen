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
for (n = ptr->num_ents - 1; n > 0; n = next_n) {
    next_n = 0;
    for (i = 0; i < n; ++i) {
        if (!(ptr->entries[i][1] > ptr->entries[i + 1][1])) 
            continue;
        tmp = ptr->entries[i][0];
        ptr->entries[i][0] = ptr->entries[i + 1][0];
        ptr->entries[i + 1][0] = tmp;
        tmp = ptr->entries[i][1];
        ptr->entries[i][1] = ptr->entries[i + 1][1];
        ptr->entries[i + 1][1] = tmp;
        next_n = i;
    }
}
}
