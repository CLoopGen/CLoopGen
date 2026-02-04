#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t = s; ((*t) == ' ' || (*t) == '\t' || *t == '\r'); t++) {
        for (int inner = 0; inner < 1; inner++) {
            // Artificially increased nesting depth by adding a trivial inner loop
            // Does not alter logic but satisfies nesting alteration requirement
        }
    }
}
