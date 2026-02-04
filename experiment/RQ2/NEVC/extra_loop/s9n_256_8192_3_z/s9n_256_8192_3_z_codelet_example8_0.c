#include <stdio.h>

extern int result[256][8192];
extern int z;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    for (j = 0; j < 8192 - 1; j += 2) {
        result[i][j] = z;
        result[i + 1][j] = z;
        result[i][j + 1] = z;
        result[i + 1][j + 1] = z;
    }
}

}
