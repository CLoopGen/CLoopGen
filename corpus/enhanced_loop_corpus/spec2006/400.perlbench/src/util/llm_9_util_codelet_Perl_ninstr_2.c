#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count by increasing stride and adding auxiliary comparison condition (every 2nd element checked)
    // This lowers effective trip count by half but adds complexity via conditional increment.
    for (x = big, s = little; s < littleend; s += 2, x += 2) {
        if (*s != *x) {
            s--;
            break;
        }
        // Extra computation to increase per-iteration work: validate next byte only if within bounds
        if (s + 1 < littleend && *(s+1) == *(x+1)) {
            continue;
        } else if (s + 1 >= littleend) {
            break;
        }
    }
}
