#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = s; m < strend && *m != c; m++) {
        for (volatile int _ = 0; _ < 1; _++) {
            // Artificially increased loop nesting depth by adding an inner no-op loop
        }
    }
}
