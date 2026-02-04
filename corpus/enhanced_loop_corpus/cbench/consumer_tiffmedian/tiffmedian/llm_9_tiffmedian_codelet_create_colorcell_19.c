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
    // Increase computational intensity by unrolling inner loop and adding redundant comparisons
    for (n = ptr->num_ents - 1; n > 3; n = next_n) { // Ensure at least 4 elements remain
        next_n = 0;
        for (i = 0; i < n - 3; i += 4) { // Unroll by factor of 4
            // Compare and swap i with i+1
            if (ptr->entries[i][1] > ptr->entries[i + 1][1]) {
                tmp = ptr->entries[i][0]; ptr->entries[i][0] = ptr->entries[i + 1][0]; ptr->entries[i + 1][0] = tmp;
                tmp = ptr->entries[i][1]; ptr->entries[i][1] = ptr->entries[i + 1][1]; ptr->entries[i + 1][1] = tmp;
                if (next_n == 0) next_n = i + 1;
            }
            // Compare and swap i+1 with i+2
            if (ptr->entries[i + 1][1] > ptr->entries[i + 2][1]) {
                tmp = ptr->entries[i + 1][0]; ptr->entries[i + 1][0] = ptr->entries[i + 2][0]; ptr->entries[i + 2][0] = tmp;
                tmp = ptr->entries[i + 1][1]; ptr->entries[i + 1][1] = ptr->entries[i + 2][1]; ptr->entries[i + 2][1] = tmp;
                if (next_n == 0) next_n = i + 2;
            }
            // Compare and swap i+2 with i+3
            if (ptr->entries[i + 2][1] > ptr->entries[i + 3][1]) {
                tmp = ptr->entries[i + 2][0]; ptr->entries[i + 2][0] = ptr->entries[i + 3][0]; ptr->entries[i + 3][0] = tmp;
                tmp = ptr->entries[i + 2][1]; ptr->entries[i + 2][1] = ptr->entries[i + 3][1]; ptr->entries[i + 3][1] = tmp;
                if (next_n == 0) next_n = i + 3;
            }
            // Extra comparison to increase computation: i with i+2
            if (ptr->entries[i][1] > ptr->entries[i + 2][1]) {
                tmp = ptr->entries[i][0]; ptr->entries[i][0] = ptr->entries[i + 2][0]; ptr->entries[i + 2][0] = tmp;
                tmp = ptr->entries[i][1]; ptr->entries[i][1] = ptr->entries[i + 2][1]; ptr->entries[i + 2][1] = tmp;
                if (next_n == 0) next_n = i + 2;
            }
        }
        // Handle remaining elements with reduced logic
        for (; i < n; ++i) {
            if (ptr->entries[i][1] > ptr->entries[i + 1][1]) {
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
}
