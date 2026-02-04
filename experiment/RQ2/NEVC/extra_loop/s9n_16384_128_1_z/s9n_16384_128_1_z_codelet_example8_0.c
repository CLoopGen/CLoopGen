#include <stdio.h>

extern int Out[16384][128];
extern int z;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    for (j = 0; j < 128 - 1; j += 2) {
        Out[i][j] = z;
        Out[i + 1][j] = z;
        Out[i][j + 1] = z;
        Out[i + 1][j + 1] = z;
    }
}

}
