#include <stdio.h>

extern int Out[256][128];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    for (j = 0; j < 128; j++) {
        Out[i][j] = x;
    }
}

}
