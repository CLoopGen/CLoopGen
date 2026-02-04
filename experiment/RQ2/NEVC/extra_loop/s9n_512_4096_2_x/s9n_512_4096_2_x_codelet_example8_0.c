#include <stdio.h>

extern int Output[512][4096];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512 - 1; i += 2) {
    for (j = 0; j < 4096 - 1; j += 2) {
        Output[i][j] = x;
        Output[i + 1][j] = x;
        Output[i][j + 1] = x;
        Output[i + 1][j + 1] = x;
    }
}

}
