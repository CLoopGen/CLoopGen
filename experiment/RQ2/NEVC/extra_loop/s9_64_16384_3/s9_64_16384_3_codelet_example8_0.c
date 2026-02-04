#include <stdio.h>

extern int result[64][16384];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 16384; j++) {
        result[i][j] = x;
    }
}

}
