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
        int temp_val = table[i][j];
        if (j - 1 >= 0)
            temp_val = ((temp_val >= table[i][j - 1]) ? temp_val : table[i][j - 1]);
        if (i + 1 < n)
            temp_val = ((temp_val >= table[i + 1][j]) ? temp_val : table[i + 1][j]);
        if (j - 1 >= 0 && i + 1 < n) {
            int bonus = (((seq[i]) + (seq[j])) == 3 ? 1 : 0);
            if (i < j - 1)
                temp_val = ((temp_val >= table[i + 1][j - 1] + bonus) ? temp_val : table[i + 1][j - 1] + bonus);
            else
                temp_val = ((temp_val >= table[i + 1][j - 1]) ? temp_val : table[i + 1][j - 1]);
        }
        for (k = i + 1; k < j; k++) {
            int sum = table[i][k] + table[k + 1][j];
            temp_val = ((temp_val >= sum) ? temp_val : sum);
        }
        table[i][j] = temp_val;
    }
}
}
