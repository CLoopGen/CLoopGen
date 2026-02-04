#include <stdio.h>

extern int result[128][64];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128 - 1; i += 2) {
    for (j = 0; j < 64 - 1; j += 2) {
        result[i][j] = y;
        result[i + 1][j] = y;
        result[i][j + 1] = y;
        result[i + 1][j + 1] = y;
    }
}

}
