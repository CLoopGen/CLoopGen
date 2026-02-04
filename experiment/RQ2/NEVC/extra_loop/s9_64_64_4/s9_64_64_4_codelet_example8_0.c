#include <stdio.h>

extern int assign[64][64];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
        assign[i][j] = x;
    }
}

}
