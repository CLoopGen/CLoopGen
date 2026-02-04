#include <stdio.h>

extern int result[512][1024];
extern int y;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512 - 1; i += 2) {
    for (j = 0; j < 1024 - 1; j += 2) {
        result[i][j] = y;
        result[i + 1][j] = y;
        result[i][j + 1] = y;
        result[i + 1][j + 1] = y;
    }
}

}
