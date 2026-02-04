#include <stdio.h>

extern int Out[64][16384];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64 - 1; i += 2) {
    for (j = 0; j < 16384 - 1; j += 2) {
        Out[i][j] = x;
        Out[i + 1][j] = x;
        Out[i][j + 1] = x;
        Out[i + 1][j + 1] = x;
    }
}

}
