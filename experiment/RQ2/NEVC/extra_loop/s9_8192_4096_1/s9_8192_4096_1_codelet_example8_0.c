#include <stdio.h>

extern int Out[8192][4096];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    for (j = 0; j < 4096; j++) {
        Out[i][j] = x;
    }
}

}
