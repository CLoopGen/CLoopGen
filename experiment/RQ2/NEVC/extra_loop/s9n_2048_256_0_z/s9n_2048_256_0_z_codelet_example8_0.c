#include <stdio.h>

extern int G[2048][256];
extern int z;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048 - 1; i += 2) {
    for (j = 0; j < 256 - 1; j += 2) {
        G[i][j] = z;
        G[i + 1][j] = z;
        G[i][j + 1] = z;
        G[i + 1][j + 1] = z;
    }
}

}
