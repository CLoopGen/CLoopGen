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
int i;
for (x = 0; x < 26; x += 2) {
    for (i = 0; i < 3; i++) {  // Increased computational intensity with inner loop
        if (x + i < 26) {
            y = E[x + i][nE[x + i] - 1];
            if (Z[x + i] == 0 && Z[y] == 1) {
                Z[x + i] = 1;
                keep_connecting = 1;
            }
        }
    }
}
}
