#include <stdio.h>

int firstrow;
int lastrow;
int firstcol;
int colidx[2198001];
int rowstr[14002];
int j;
int k;

void init_vars() {
    firstrow = 1;
    lastrow = 14000;
    firstcol = 1;
    
    for (int i = 0; i <= 14001; i++) {
        rowstr[i] = (i * 156); 
    }
    
    for (int i = 0; i < 2198001; i++) {
        colidx[i] = (i % 1000) + 1;
    }
}