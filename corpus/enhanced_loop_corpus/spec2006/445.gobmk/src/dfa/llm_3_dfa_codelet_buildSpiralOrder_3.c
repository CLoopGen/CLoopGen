#include <stdio.h>

#include <inttypes.h>

extern  int generator[4];
extern int mark[7056];
extern int fifo[14112];
extern int top;
extern int k;
extern int ii;
extern int delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access Pattern via Index Mapping
    // Use an index remapping table to access generator in non-sequential order
    int index_map[4] = {3, 1, 0, 2};  // Custom permutation for indirect access
    for (k = 0; k != 4; k++) {
        int mapped_index = index_map[k];  // Indirect access through mapping
        delta = generator[mapped_index];
        if (!mark[ii + delta]) {
            fifo[top] = ii + delta;
            mark[ii + delta] = 1;
            top++;
        }
    }
}
