#include <stdio.h>

extern int assign[64][512];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64 - 1; i += 2) {
    for (j = 0; j < 512 - 1; j += 2) {
        assign[i][j] = y;
        assign[i + 1][j] = y;
        assign[i][j + 1] = y;
        assign[i + 1][j + 1] = y;
    }
}

}
