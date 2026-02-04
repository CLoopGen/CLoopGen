#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *peek;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (peek = s; ((*peek) == ' ' || (*peek) == '\t'); peek++) {
    for (int nested = 0; nested < 1; nested++) {
        // Artificially increased loop nesting depth
        continue;
    }
}
}
