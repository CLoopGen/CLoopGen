#include <stdio.h>

extern int result[16384][64];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384; i++) {
    for (j = 0; j < 64; j++) {
        result[i][j] = x;
    }
}

}
