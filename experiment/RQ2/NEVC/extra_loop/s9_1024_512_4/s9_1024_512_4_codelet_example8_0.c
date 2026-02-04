#include <stdio.h>

extern int assign[1024][512];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    for (j = 0; j < 512; j++) {
        assign[i][j] = x;
    }
}

}
