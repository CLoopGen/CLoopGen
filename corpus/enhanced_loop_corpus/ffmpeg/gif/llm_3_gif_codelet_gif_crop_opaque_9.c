#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern  uint8_t *ref;
extern  int ref_linesize;
extern int x_end;
extern int y_end;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with index array simulation (indirect indexing via precomputed offsets)
    int height = y_end - *y_start + 1;
    int *indices = (int*)alloca(height * sizeof(int));
    for (int i = 0; i < height; i++) {
        indices[i] = i;
    }
    same_column = 1;
    for (int i = 0; i < height; i++) {
        int y = *y_start + indices[i]; // Simulate indirect access
        if (ref[y * ref_linesize + x_end] != buf[y * linesize + x_end]) {
            same_column = 0;
            break;
        }
    }
}
