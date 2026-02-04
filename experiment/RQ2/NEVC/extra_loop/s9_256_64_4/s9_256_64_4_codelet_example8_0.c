#include <stdio.h>

extern int assign[256][64];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    for (j = 0; j < 64; j++) {
        assign[i][j] = x;
    }
}

}
