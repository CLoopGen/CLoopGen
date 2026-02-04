#include <stdio.h>

extern int G[2048][1024];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048; i++) {
    for (j = 0; j < 1024; j++) {
        G[i][j] = x;
    }
}

}
