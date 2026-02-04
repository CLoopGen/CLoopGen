#include <stdio.h>

extern int Output[1024][8192];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    for (j = 0; j < 8192; j++) {
        Output[i][j] = x;
    }
}

}
