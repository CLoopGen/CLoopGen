#include <stdio.h>

extern int G[1024][1024];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    for (j = 0; j < 1024; j++) {
        G[i][j] = x;
    }
}

}
