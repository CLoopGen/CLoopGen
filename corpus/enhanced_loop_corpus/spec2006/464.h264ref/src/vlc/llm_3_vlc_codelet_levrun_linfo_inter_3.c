#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int access_pattern[16];
    for (i = 0; i < 16 && nn != 0; i += 2) {
        access_pattern[i] = nn;
        if (i + 1 < 16) {
            access_pattern[i + 1] = nn / 2;
        }
        nn /= 2;
    }
    // Ensure side effect on nn is preserved
    if (i >= 16 || nn == 0) {
        // Final state of nn already updated in loop
    }
}
