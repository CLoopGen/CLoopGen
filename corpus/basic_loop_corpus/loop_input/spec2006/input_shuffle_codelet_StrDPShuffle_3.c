#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x;
int y;
char **E;
int *nE;
char Z[26];
int keep_connecting;

void init_vars() {
    // Initialize Z array to control state transitions
    for (int i = 0; i < 26; i++) {
        Z[i] = (i % 2 == 0) ? 1 : 0;  // Alternate initial states
    }

    // Allocate and initialize nE: each entry determines length of E[x]
    nE = (int*)calloc(26, sizeof(int));
    for (int i = 0; i < 26; i++) {
        nE[i] = (i + 1) * 15000 + 1;  // Increasing sizes to total ~multi-megabyte data
    }

    // Allocate E as array of 26 char pointers
    E = (char**)malloc(26 * sizeof(char*));
    if (!E) return;

    // Total estimated data size: ~100-200 MB to target ~0.01 sec runtime
    for (int i = 0; i < 26; i++) {
        E[i] = (char*)malloc(nE[i] * sizeof(char));
        if (E[i]) {
            // Fill with cyclic lowercase-like index patterns
            for (int j = 0; j < nE[i]; j++) {
                E[i][j] = 'a' + (j % 26);
            }
            // Ensure last element maps to valid index 0-25
            E[i][nE[i]-1] = i % 26;  // guarantees y is in [0,25]
        }
    }

    // Initialize control flag
    keep_connecting = 0;

    // Initialize loop counters
    x = 0;
    y = 0;
}