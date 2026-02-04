#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y_start;
extern int y;
extern int x_end;
extern int y_end;
extern  uint32_t *prv_srcp;
extern  uint32_t *cur_srcp;
extern  int prv_src_linesize;
extern  int cur_src_linesize;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order and indirect indexing via pointer arrays
    // Simulate indirect access pattern using an index map (identity in this case, but structure allows generalization)
    int range = y_end - y_start + 1;
    int *indices = (int*)alloca(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        indices[i] = y_end - i; // Reverse iteration order: descending y
    }

    for (int i = 0; i < range; i++) {
        int y_val = y_start + indices[i]; // Indirect access through shuffled index
        if (prv_srcp[y_val * prv_src_linesize + x_end] != cur_srcp[y_val * cur_src_linesize + x_end]) {
            same_column = 0;
            break;
        }
    }
}
