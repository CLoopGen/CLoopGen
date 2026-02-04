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
        int sum = i + j;
        if ((sum % 13 == 0) | (sum % 7 == 0) | (sum % 11 == 0)) {
            path[i][j] = 999;
        } else {
            path[i][j] = i * j % 7 + 1;
        }
    }
}
