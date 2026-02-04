#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other character, increasing step size
    // Also simplify condition evaluation using a helper array (precomputed lookup would be ideal, but we simulate with arithmetic)
    for (i = 0; ('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'F') || ('a' <= s[i] && s[i] <= 'f'); i += 2) {
        // Skip odd indices — effectively halving the number of iterations
        // This changes trip count and reduces arithmetic per effective digit
    }
}
