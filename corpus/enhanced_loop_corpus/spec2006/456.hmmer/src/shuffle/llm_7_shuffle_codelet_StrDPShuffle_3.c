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
    keep_connecting = 0;
    for (x = 25; x >= 0; x--) {
        int prev_index = (x > 0) ? x - 1 : 0;
        y = E[prev_index][nE[prev_index] - 1];
        if (Z[prev_index] == 0 && Z[y] == 1) {
            Z[prev_index] = 1;
            keep_connecting = 1;
        }
    }
}
