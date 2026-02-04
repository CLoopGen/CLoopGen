#include <stdio.h>

extern int G[8192][512];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    for (j = 0; j < 512; j++) {
        G[i][j] = x;
    }
}

}
