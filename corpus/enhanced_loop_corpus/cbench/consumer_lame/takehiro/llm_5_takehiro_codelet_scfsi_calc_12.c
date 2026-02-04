#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int ch;
extern III_scalefac_t scalefac[2][2];
extern int s1;
extern int c1;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sfb = 0; sfb < 11; sfb++) {
        int value = scalefac[1][ch].l[sfb];
        if (value < 0) {
            // Skip processing, but introduce an additional check to simulate refined control
            if (sfb % 2 == 0) {
                continue;
            } else {
                c1--; // Artificial adjustment to differentiate path behavior
            }
        } else {
            c1++;
            s1 = (s1 < value) ? value : s1; // Replace conditional assignment with ternary
        }
    }
}
