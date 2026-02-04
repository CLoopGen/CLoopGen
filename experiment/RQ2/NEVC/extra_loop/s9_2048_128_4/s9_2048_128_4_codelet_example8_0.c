#include <stdio.h>

extern int assign[2048][128];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048; i++) {
    for (j = 0; j < 128; j++) {
        assign[i][j] = x;
    }
}

}
