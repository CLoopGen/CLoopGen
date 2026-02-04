#include <stdio.h>

extern int G[128][2048];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128; i++) {
    for (j = 0; j < 2048; j++) {
        G[i][j] = x;
    }
}

}
