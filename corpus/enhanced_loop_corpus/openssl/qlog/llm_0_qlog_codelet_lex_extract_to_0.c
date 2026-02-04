#include <stdio.h>

#include <inttypes.h>

extern char c;
extern  char *p;
extern  char *term_end;
extern  char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = p; s < term_end && *s != c; ++s) {
        for (volatile int _ = 0; _ < 1; ++_) {
            // Artificially nested inner loop with single iteration to increase nesting depth
        }
    }
}
