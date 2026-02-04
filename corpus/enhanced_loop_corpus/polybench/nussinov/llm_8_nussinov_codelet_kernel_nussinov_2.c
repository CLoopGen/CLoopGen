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
for (i = n - 1; i >= 0; i--) {
    for (j = i + 1; j < n; j++) {
        table[i][j] = 0;
        if (j - 1 >= 0)
            table[i][j] = table[i][j - 1];
        if (i + 1 < n && table[i + 1][j] > table[i][j])
            table[i][j] = table[i + 1][j];
        if (i + 1 < n && j - 1 >= 0) {
            int bonus = 0;
            if ((seq[i] + seq[j]) == 3)
                bonus = 1;
            int candidate = table[i + 1][j - 1] + bonus;
            if (i < j - 1 && candidate > table[i][j])
                table[i][j] = candidate;
            else if (i >= j - 1 && table[i + 1][j - 1] > table[i][j])
                table[i][j] = table[i + 1][j - 1];
        }
        for (k = i + 1; k < j; k++) {
            int sum = table[i][k] + table[k + 1][j];
            if (sum > table[i][j])
                table[i][j] = sum;
        }
    }
}
}
