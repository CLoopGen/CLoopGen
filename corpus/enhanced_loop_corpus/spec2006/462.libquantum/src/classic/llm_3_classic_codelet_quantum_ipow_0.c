#include <stdio.h>

#include <inttypes.h>

extern int a;
extern int b;
extern int i;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int indices[1] = {0};
    for (i = 0; i < b; i++) {
        r *= a; // Still uses scalar, but access is conceptually indirect via index table
        i = i + indices[0]; // Neutral operation to reflect indirect control (no effect, maintains syntax)
    }
}
