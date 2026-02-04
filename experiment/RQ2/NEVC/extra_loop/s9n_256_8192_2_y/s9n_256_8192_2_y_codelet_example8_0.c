#include <stdio.h>

extern int Output[256][8192];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    for (j = 0; j < 8192 - 1; j += 2) {
        Output[i][j] = y;
        Output[i + 1][j] = y;
        Output[i][j + 1] = y;
        Output[i + 1][j + 1] = y;
    }
}

}
