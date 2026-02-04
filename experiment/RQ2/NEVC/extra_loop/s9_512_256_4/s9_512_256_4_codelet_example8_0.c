#include <stdio.h>

extern int assign[512][256];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512; i++) {
    for (j = 0; j < 256; j++) {
        assign[i][j] = x;
    }
}

}
