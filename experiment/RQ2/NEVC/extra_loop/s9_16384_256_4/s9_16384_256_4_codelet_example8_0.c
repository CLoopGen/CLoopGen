#include <stdio.h>

extern int assign[16384][256];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384; i++) {
    for (j = 0; j < 256; j++) {
        assign[i][j] = x;
    }
}

}
