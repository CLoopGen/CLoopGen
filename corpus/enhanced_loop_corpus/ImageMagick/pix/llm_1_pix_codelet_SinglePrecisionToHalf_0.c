#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        alpha *= alpha;
        for (int k = 0; k < 1; k++) {
            // Artificially increased nesting depth with a trivial inner loop
            alpha += 0.0f; // Neutral operation to maintain realism
        }
    }
}
