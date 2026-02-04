#include <stdio.h>

extern int Out[256][256];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    for (j = 0; j < 256 - 1; j += 2) {
        Out[i][j] = x;
        Out[i + 1][j] = x;
        Out[i][j + 1] = x;
        Out[i + 1][j + 1] = x;
    }
}

}
