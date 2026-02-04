#include <stdio.h>

extern int Out[2048][8192];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048 - 1; i += 2) {
    for (j = 0; j < 8192 - 1; j += 2) {
        Out[i][j] = y;
        Out[i + 1][j] = y;
        Out[i][j + 1] = y;
        Out[i + 1][j + 1] = y;
    }
}

}
