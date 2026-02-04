#include <stdio.h>

extern int Output[1024][16384];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024 - 1; i += 2) {
    for (j = 0; j < 16384 - 1; j += 2) {
        Output[i][j] = x;
        Output[i + 1][j] = x;
        Output[i][j + 1] = x;
        Output[i + 1][j + 1] = x;
    }
}

}
