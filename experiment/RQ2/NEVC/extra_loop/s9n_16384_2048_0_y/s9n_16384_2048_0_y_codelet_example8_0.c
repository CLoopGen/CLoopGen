#include <stdio.h>

extern int G[16384][2048];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    for (j = 0; j < 2048 - 1; j += 2) {
        G[i][j] = y;
        G[i + 1][j] = y;
        G[i][j + 1] = y;
        G[i + 1][j + 1] = y;
    }
}

}
