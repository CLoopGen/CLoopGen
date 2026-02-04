#include <stdio.h>

extern int assign[128][8192];
extern int z;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128 - 1; i += 2) {
    for (j = 0; j < 8192 - 1; j += 2) {
        assign[i][j] = z;
        assign[i + 1][j] = z;
        assign[i][j + 1] = z;
        assign[i + 1][j + 1] = z;
    }
}

}
