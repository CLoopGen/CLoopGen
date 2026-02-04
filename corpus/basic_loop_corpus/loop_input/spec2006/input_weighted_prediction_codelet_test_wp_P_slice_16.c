#include <stdio.h>
#include <inttypes.h>

#define index _usr_index

// External variable definitions
int listXsize[6] = {15, 15, 15, 15, 15, 15}; // All arrays have size 15
int _usr_index = 0;
int comp = 0;
int default_weight = 42;
int list_offset = 0;
int weight[2][15][3];
int offset[2][15][3];
int clist = 0;
int perform_wp = 0;

void init_vars() {
    // Initialize weight and offset arrays to mostly default values
    // so that the loop runs deep before triggering perform_wp = 1.
    // We set one value near the end to trigger the condition.

    for (int c = 0; c < 2; c++) {
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 3; j++) {
                weight[c][i][j] = default_weight;
                offset[c][i][j] = 0;
            }
        }
    }

    // Set a non-default value at the very end to ensure long execution
    // This will cause perform_wp = 1 only at the last possible moment
    weight[1][14][2] = default_weight + 1;

    // Adjust list sizes to be within bounds: only use first 2 elements due to loop condition
    listXsize[0] = 15;
    listXsize[1] = 15;
    // The rest are unused due to clist < 2 + list_offset and list_offset = 0 => clist < 2
    listXsize[2] = 15;
    listXsize[3] = 15;
    listXsize[4] = 15;
    listXsize[5] = 15;

    // Reset control variables
    _usr_index = 0;
    comp = 0;
    clist = 0;
    perform_wp = 0;
}