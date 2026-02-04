#include <stdio.h>

extern int result[1024][128];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024 - 1; i += 2) {
    for (j = 0; j < 128 - 1; j += 2) {
        result[i][j] = x;
        result[i + 1][j] = x;
        result[i][j + 1] = x;
        result[i + 1][j + 1] = x;
    }
}

}
