#include <stdio.h>

extern int result[64][256];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 256; j++) {
        result[i][j] = x;
    }
}

}
