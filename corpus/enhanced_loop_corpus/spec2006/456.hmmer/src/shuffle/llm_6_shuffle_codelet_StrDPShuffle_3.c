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
    int temp_Z[26];
    for (x = 0; x < 26; x++) {
        temp_Z[x] = Z[x];
    }
    keep_connecting = 0;
    for (x = 0; x < 26; x++) {
        y = E[x][nE[x] - 1];
        if (temp_Z[x] == 0 && temp_Z[y] == 1) {
            Z[x] = 1;
            keep_connecting = 1;
        }
    }
}
