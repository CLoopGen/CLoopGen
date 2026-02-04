#include <stdio.h>

extern int assign[4096][2048];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 4096; i++) {
    for (j = 0; j < 2048; j++) {
        assign[i][j] = x;
    }
}

}
