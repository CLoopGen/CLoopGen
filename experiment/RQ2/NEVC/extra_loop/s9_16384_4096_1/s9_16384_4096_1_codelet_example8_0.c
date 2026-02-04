#include <stdio.h>

extern int Out[16384][4096];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384; i++) {
    for (j = 0; j < 4096; j++) {
        Out[i][j] = x;
    }
}

}
