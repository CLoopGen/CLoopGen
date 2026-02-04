#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    for (i = 0; i < 3; i++) {
        dims[i][0] = 256;
        dims[i][1] = dims[i][0];  // Introduce RAW dependency: use dims[i][0] just written
        dims[i][2] = dims[i][1];  // Another RAW dependency: depends on previous assignment
    }
}
