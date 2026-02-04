#include <stdio.h>
#include <inttypes.h>

int i;
int LoopArray[25];

int predpel_data[27]; // Size to accommodate indices from -1 to 25 safely
int *PredPel = predpel_data + 1; // Point to actual start so that [i-1], [i], [i+1] are valid for i from 18 to 23

void init_vars() {
    // Initialize PredPel base data (accessed from index 0 to 24 in the loop)
    for (int idx = 0; idx < 25; idx++) {
        predpel_data[idx] = (idx * idx) & 0xFF; // Arbitrary non-zero pattern
    }

    // Initialize LoopArray with known values
    for (int idx = 0; idx < 25; idx++) {
        LoopArray[idx] = 0;
    }

    // Initialize scalar variables
    i = 0;
}