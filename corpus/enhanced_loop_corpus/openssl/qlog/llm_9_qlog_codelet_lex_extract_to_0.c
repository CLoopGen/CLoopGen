#include <stdio.h>

#include <inttypes.h>

extern char c;
extern  char *p;
extern  char *term_end;
extern  char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count by unrolling with stride of 4, includes early exit checks
    // Fewer iterations with more work per loop cycle; uses arithmetic expansion for complexity
    char *temp;
    for (s = p; s < term_end; ) {
        temp = s;
        s += 4;
        if (temp < term_end && *temp == c) {
            s = temp;
            break;
        }
        temp++;
        if (temp < term_end && *temp == c) {
            s = temp;
            break;
        }
        temp++;
        if (temp < term_end && *temp == c) {
            s = temp;
            break;
        }
        temp++;
        if (temp < term_end && *temp == c) {
            s = temp;
            break;
        }
        if (s >= term_end) {
            s = temp;
            for (; s < term_end && *s != c; ++s)
                ;
            break;
        }
    }
}
