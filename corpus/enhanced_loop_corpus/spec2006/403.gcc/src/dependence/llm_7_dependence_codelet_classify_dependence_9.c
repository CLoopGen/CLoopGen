#include <stdio.h>

#include <inttypes.h>

extern int *separability;
extern int count;
extern  char *iiv_used[13];
extern  char *oiv_used[13];
extern int idx;
extern int cidx;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_sep = 1; // Eliminate direct write to shared *separability initially
    for (idx = 1; idx <= count; idx++) {
        int found_match = 0; // Introduce per-iteration dependency (loop-carried via reduction)
        for (cidx = 1; cidx <= count; cidx++) {
            if (idx != cidx && iiv_used[idx] && oiv_used[cidx] && iiv_used[idx] == oiv_used[cidx]) {
                found_match = 1;
                break; // Introduce control dependence and early exit (alters data flow)
            }
        }
        local_sep &= !found_match; // Reduction: loop-carried dependence via cumulative AND
    }
    if (!local_sep) {
        *separability = 0; // Single write at end — minimal WAW, no loop-carried store
    }
}
