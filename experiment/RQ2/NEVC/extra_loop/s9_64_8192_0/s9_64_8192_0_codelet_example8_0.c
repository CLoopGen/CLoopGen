#include <stdio.h>

extern int G[64][8192];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 8192; j++) {
        G[i][j] = x;
    }
}

}
