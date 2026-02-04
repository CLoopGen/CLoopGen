#include <stdio.h>

extern int Out[512][16384];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512; i++) {
    for (j = 0; j < 16384; j++) {
        Out[i][j] = x;
    }
}

}
