#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int table[2500][2500];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n - 1; i >= 0; i -= 2) {
    for (j = i + 2; j < n; j += 2) {
        if (j - 2 >= 0)
            table[i][j] = (table[i][j] >= table[i][j - 2]) ? table[i][j] : table[i][j - 2];
        if (i + 2 < n)
            table[i][j] = (table[i][j] >= table[i + 2][j]) ? table[i][j] : table[i + 2][j];
        if (j - 2 >= 0 && i + 2 < n) {
            int add = ((seq[i] + seq[j]) == 3) ? 1 : 0;
            table[i][j] = (table[i][j] >= table[i + 2][j - 2] + add) ? table[i][j] : table[i + 2][j - 2] + add;
        }
        for (k = i + 2; k < j; k += 2) {
            int temp = table[i][k] + table[k + 1][j];
            if (temp > table[i][j])
                table[i][j] = temp;
        }
    }
}
}
