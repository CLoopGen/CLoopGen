#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int table[2500][2500];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < n; i++) {
        temp = 0;
        for (j = 0; j < n; j++) {
            temp += i + j;
        }
        for (j = 0; j < n; j++) {
            table[i][j] = temp;
        }
    }

}
