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
            // Additional inner loop with minimal iteration to increase nesting depth
            alpha += 0.0f; // No-op effect, maintains realism and avoids optimization away
        }
    }
}
