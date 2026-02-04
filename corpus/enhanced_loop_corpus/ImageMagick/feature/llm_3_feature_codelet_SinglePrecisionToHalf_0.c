#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float history[11];
    history[0] = alpha;
    for (i = 1; i <= 10; i++) {
        // Consecutive access in array: each value depends on previous
        history[i] = history[i-1] * history[i-1];
    }
    alpha = history[10];  // Final result after 10 squarings
}
