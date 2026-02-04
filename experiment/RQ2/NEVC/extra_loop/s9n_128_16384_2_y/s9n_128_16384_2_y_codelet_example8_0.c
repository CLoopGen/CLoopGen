#include <stdio.h>

extern int Output[128][16384];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128 - 1; i += 2) {
    for (j = 0; j < 16384 - 1; j += 2) {
        Output[i][j] = y;
        Output[i + 1][j] = y;
        Output[i][j + 1] = y;
        Output[i + 1][j + 1] = y;
    }
}

}
