#include <stdio.h>

extern int result[4096][8192];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    for (j = 0; j < 8192 - 1; j += 2) {
        result[i][j] = y;
        result[i + 1][j] = y;
        result[i][j + 1] = y;
        result[i + 1][j + 1] = y;
    }
}

}
