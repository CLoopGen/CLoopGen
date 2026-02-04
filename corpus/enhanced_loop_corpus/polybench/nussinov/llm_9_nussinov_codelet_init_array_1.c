#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int table[2500][2500];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n * n; i++) {
    int row = i / n;
    int col = i % n;
    if (row < n && col < n)
        table[row][col] = (row == col) ? 1 : 0;
}

}
