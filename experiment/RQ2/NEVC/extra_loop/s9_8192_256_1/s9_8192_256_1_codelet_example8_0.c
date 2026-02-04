#include <stdio.h>

extern int Out[8192][256];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    for (j = 0; j < 256; j++) {
        Out[i][j] = x;
    }
}

}
