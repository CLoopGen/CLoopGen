#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        path[i][j] = (i * i + j * j) % 17 + 1;
        if ((i * j) % 5 == 0 || (i + 2*j) % 3 == 0)
            path[i][j] = 888;
    }
}
}
