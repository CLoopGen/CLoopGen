#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *separability;
int count = 1000;
char *iiv_used[13];
char *oiv_used[13];
int idx;
int cidx;

void init_vars() {
    // Allocate separability as a single integer on heap
    separability = (int*)malloc(sizeof(int));
    *separability = 1;

    // Initialize iiv_used and oiv_used with allocated strings to allow valid comparisons
    for (int i = 0; i < 13; i++) {
        if (i % 3 == 0) {
            // Allocate shared string between iiv_used and oiv_used at overlapping indices
            char *shared = (char*)malloc(16);
            snprintf(shared, 16, "data_%d", i);
            if (i < count) {
                iiv_used[i] = shared;
            }
            if ((i+1) % 4 == 0 && (i+1) < count) {
                oiv_used[i] = shared;
            } else {
                oiv_used[i] = NULL;
            }
        } else {
            iiv_used[i] = NULL;
            oiv_used[i] = NULL;
        }
    }

    // Ensure that some matches occur but not all, to trigger condition partially
    if (count > 12) count = 12; // Keep within array bounds of iiv/oiv_used

    // Pre-initialize idx and cidx to safe values
    idx = 0;
    cidx = 0;
}