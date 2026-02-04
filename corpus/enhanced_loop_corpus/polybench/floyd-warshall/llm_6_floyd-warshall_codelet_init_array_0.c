#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
        int temp = (i + j) % 13;
        int val = i * j % 7 + 1;
        if (temp == 0 || (i + j) % 7 == 0 || (i + j) % 11 == 0)
            val = 999;
        path[i][j] = val;
    }
}
