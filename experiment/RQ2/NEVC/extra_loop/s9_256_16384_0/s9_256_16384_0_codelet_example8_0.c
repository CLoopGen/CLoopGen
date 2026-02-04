#include <stdio.h>

extern int G[256][16384];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    for (j = 0; j < 16384; j++) {
        G[i][j] = x;
    }
}

}
