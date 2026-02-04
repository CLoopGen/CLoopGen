#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int ch;
extern III_scalefac_t scalefac[2][2];
extern int s2;
extern int c2;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce artificial loop-carried WAW and RAW dependencies
    // by splitting the logic and reordering operations with a shadow variable

    int prev_l_value = 0; // Artificial state to create loop-carried RAW/WAW

    for (; sfb < 21; sfb++) {
        int current = scalefac[1][ch].l[sfb];

        // Create artificial dependency: current iteration depends on prior modified state
        int adjusted = current + prev_l_value; // RAW: uses previous iteration's output

        if (adjusted < 0) {
            prev_l_value = 0;
            continue;
        }

        c2++;
        if (s2 < current)
            s2 = current;

        // WAW hazard introduced via write to shared state in ordered sequence
        prev_l_value = current; // Feed into next iteration, creating loop-carried dependence
    }
}
