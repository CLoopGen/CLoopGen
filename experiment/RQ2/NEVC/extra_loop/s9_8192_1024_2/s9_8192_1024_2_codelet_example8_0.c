#include <stdio.h>

extern int Output[8192][1024];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    for (j = 0; j < 1024; j++) {
        Output[i][j] = x;
    }
}

}
