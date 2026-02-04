#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int y;
extern char **E;
extern int *nE;
extern char Z[26];
extern int keep_connecting;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing E[x] and nE[x] with unit stride, traverse with a stride of 2 (unrolled-like pattern)
    // Handle even and odd indices in separate passes to create strided access

    for (x = 0; x < 26; x += 2) {
        y = E[x][nE[x] - 1];
        if (Z[x] == 0 && Z[y] == 1) {
            Z[x] = 1;
            keep_connecting = 1;
        }
    }
    for (x = 1; x < 26; x += 2) {
        y = E[x][nE[x] - 1];
        if (Z[x] == 0 && Z[y] == 1) {
            Z[x] = 1;
            keep_connecting = 1;
        }
    }
}
