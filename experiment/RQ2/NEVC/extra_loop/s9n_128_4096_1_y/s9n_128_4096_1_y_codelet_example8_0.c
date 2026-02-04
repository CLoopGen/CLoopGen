#include <stdio.h>

extern int Out[128][4096];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128 - 1; i += 2) {
    for (j = 0; j < 4096 - 1; j += 2) {
        Out[i][j] = y;
        Out[i + 1][j] = y;
        Out[i][j + 1] = y;
        Out[i + 1][j + 1] = y;
    }
}

}
