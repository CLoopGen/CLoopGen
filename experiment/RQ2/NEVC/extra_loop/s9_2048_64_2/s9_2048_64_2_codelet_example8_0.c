#include <stdio.h>

extern int Output[2048][64];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048; i++) {
    for (j = 0; j < 64; j++) {
        Output[i][j] = x;
    }
}

}
