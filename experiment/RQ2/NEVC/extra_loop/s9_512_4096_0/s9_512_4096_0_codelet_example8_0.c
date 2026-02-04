#include <stdio.h>

extern int G[512][4096];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512; i++) {
    for (j = 0; j < 4096; j++) {
        G[i][j] = x;
    }
}

}
