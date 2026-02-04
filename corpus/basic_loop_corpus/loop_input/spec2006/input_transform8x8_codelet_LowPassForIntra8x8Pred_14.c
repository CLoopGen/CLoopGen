#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int *PredPel;
int i;
int LoopArray[25];

void init_vars() {
    // Allocate and initialize PredPel with 25 integers to match loop bounds
    PredPel = (int*)malloc(25 * sizeof(int));
    if (PredPel == NULL) {
        // In case malloc fails, ensure defined behavior
        return;
    }
    for (int j = 0; j < 25; j++) {
        PredPel[j] = j; // Initialize with sample data
    }
    // Initialize loop index
    i = 0;
}