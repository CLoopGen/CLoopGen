#include <stdio.h>

extern int result[256][2048];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    for (j = 0; j < 2048 - 1; j += 2) {
        result[i][j] = y;
        result[i + 1][j] = y;
        result[i][j + 1] = y;
        result[i + 1][j + 1] = y;
    }
}

}
