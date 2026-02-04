#include <stdio.h>

extern int assign[128][128];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128; i++) {
    for (j = 0; j < 128; j++) {
        assign[i][j] = x;
    }
}

}
