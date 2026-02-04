#include <stdio.h>

extern int Output[16384][4096];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    for (j = 0; j < 4096 - 1; j += 2) {
        Output[i][j] = y;
        Output[i + 1][j] = y;
        Output[i][j + 1] = y;
        Output[i + 1][j + 1] = y;
    }
}

}
