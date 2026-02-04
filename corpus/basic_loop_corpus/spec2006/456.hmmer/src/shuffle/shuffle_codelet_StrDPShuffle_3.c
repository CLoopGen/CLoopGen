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
for (x = 0; x < 26; x++) {
    y = E[x][nE[x] - 1];
    if (Z[x] == 0 && Z[y] == 1) {
        Z[x] = 1;
        keep_connecting = 1;
    }
}

}
