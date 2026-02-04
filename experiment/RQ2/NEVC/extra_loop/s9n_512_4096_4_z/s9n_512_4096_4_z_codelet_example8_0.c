#include <stdio.h>

extern int assign[512][4096];
extern int z;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512 - 1; i += 2) {
    for (j = 0; j < 4096 - 1; j += 2) {
        assign[i][j] = z;
        assign[i + 1][j] = z;
        assign[i][j + 1] = z;
        assign[i + 1][j + 1] = z;
    }
}

}
