#include <stdio.h>

extern int G[512][256];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512 - 1; i += 2) {
    for (j = 0; j < 256 - 1; j += 2) {
        G[i][j] = y;
        G[i + 1][j] = y;
        G[i][j + 1] = y;
        G[i + 1][j + 1] = y;
    }
}

}
