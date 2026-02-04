#include <stdio.h>

extern int result[1024][2048];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    for (j = 0; j < 2048; j++) {
        result[i][j] = x;
    }
}

}
