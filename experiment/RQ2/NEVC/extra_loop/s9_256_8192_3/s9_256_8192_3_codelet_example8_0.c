#include <stdio.h>

extern int result[256][8192];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    for (j = 0; j < 8192; j++) {
        result[i][j] = x;
    }
}

}
