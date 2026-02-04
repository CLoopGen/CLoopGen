#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; (i * c) % n != 1; i++) {
        for (int j = 0; j < 1; j++) {
            // Artificially increased loop nesting depth by adding a trivial inner loop
        }
    }
}
