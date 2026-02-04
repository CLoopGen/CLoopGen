#include <stdio.h>

extern int G[8192][8192];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192 - 1; i += 2) {
    for (j = 0; j < 8192 - 1; j += 2) {
        G[i][j] = x;
        G[i + 1][j] = x;
        G[i][j + 1] = x;
        G[i + 1][j + 1] = x;
    }
}

}
