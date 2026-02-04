#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m1;
extern  unsigned char *m2;
extern char *p;
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < j; i++) {
        unsigned char val1 = m1[i];
        unsigned char val2 = m2[i];
        char replace_char = (val1 == val2) ? ' ' : '^';
        if (replace_char == '^') {
            diff = 1;
        }
        // Introduce artificial WAW dependency by updating same location twice in different ways
        *p = replace_char;
        p++;
        *p = replace_char;
        p++;
        // Add loop-carried dependency via conditional update of a temporary that affects future writes
        static char last_was_space = 0;
        if (i % 8 == 7 && i != j - 1) {
            *p = ' ';
            p++;
            last_was_space = 1;
        } else {
            last_was_space = 0;
        }
    }
}
