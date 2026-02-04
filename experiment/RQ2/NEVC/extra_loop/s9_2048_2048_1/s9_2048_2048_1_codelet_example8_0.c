#include <stdio.h>

extern int Out[2048][2048];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048; i++) {
    for (j = 0; j < 2048; j++) {
        Out[i][j] = x;
    }
}

}
