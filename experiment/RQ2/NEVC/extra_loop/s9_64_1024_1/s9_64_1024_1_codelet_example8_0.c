#include <stdio.h>

extern int Out[64][1024];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 1024; j++) {
        Out[i][j] = x;
    }
}

}
