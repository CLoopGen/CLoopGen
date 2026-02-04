#include <stdio.h>

extern int G[256][64];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    for (j = 0; j < 64 - 1; j += 2) {
        G[i][j] = x;
        G[i + 1][j] = x;
        G[i][j + 1] = x;
        G[i + 1][j + 1] = x;
    }
}

}
