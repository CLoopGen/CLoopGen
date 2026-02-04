#include <stdio.h>

extern int result[1024][512];
extern int z;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024 - 1; i += 2) {
    for (j = 0; j < 512 - 1; j += 2) {
        result[i][j] = z;
        result[i + 1][j] = z;
        result[i][j + 1] = z;
        result[i + 1][j + 1] = z;
    }
}

}
