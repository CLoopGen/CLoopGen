#include <stdio.h>

extern int Output[4096][1024];
extern int z;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    for (j = 0; j < 1024 - 1; j += 2) {
        Output[i][j] = z;
        Output[i + 1][j] = z;
        Output[i][j + 1] = z;
        Output[i + 1][j + 1] = z;
    }
}

}
