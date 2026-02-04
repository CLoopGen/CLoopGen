#include <stdio.h>

#include <inttypes.h>

enum complexity_type {
    ziv,
    strong_siv,
    weak_siv,
    weak_zero_siv,
    weak_crossing_siv,
    miv
};


extern enum complexity_type complexity[13];
extern int count;
extern  char *iiv_used[13];
extern  char *oiv_used[13];
extern int ocoeff[13];
extern int icoeff[13];
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependence by making each iteration depend on the previous
    int prev_idx = 1;
    for (idx = 1; idx <= count; idx++) {
        int current = idx;
        // Create RAW dependency: current use of 'prev_idx' depends on prior write
        if (prev_idx > 1 && iiv_used[prev_idx-1] != 0) {
            // Artificially induce a sequential dependence
            complexity[prev_idx] = complexity[prev_idx-1]; // WAW and loop-carried flow dep
        }
        if (iiv_used[current] == 0 && oiv_used[current] == 0)
            complexity[current] = ziv;
        else if (iiv_used[current] == oiv_used[current]) {
            if (icoeff[current] == ocoeff[current])
                complexity[current] = strong_siv;
            else if (icoeff[current] == -1 * ocoeff[current])
                complexity[current] = weak_crossing_siv;
            else
                complexity[current] = weak_siv;
        } else if (icoeff[current] == 0 || ocoeff[current] == 0)
            complexity[current] = weak_zero_siv;
        else
            complexity[current] = miv;
        prev_idx = current; // Update for next iteration dependence
    }
}
