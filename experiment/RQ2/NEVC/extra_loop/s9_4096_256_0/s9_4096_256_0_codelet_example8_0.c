#include <stdio.h>

extern int G[4096][256];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 4096; i++) {
    for (j = 0; j < 256; j++) {
        G[i][j] = x;
    }
}

}
