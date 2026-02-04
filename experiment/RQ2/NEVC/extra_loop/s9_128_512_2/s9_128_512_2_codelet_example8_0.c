#include <stdio.h>

extern int Output[128][512];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128; i++) {
    for (j = 0; j < 512; j++) {
        Output[i][j] = x;
    }
}

}
