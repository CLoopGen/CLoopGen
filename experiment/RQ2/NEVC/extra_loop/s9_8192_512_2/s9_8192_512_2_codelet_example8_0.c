#include <stdio.h>

extern int Output[8192][512];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    for (j = 0; j < 512; j++) {
        Output[i][j] = x;
    }
}

}
