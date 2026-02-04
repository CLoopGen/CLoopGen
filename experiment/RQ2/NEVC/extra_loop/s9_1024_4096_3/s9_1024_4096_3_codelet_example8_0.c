#include <stdio.h>

extern int result[1024][4096];
extern int x;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    for (j = 0; j < 4096; j++) {
        result[i][j] = x;
    }
}

}
