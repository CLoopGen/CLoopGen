#include <stdio.h>
#include <inttypes.h>

int m;
unsigned int a;
unsigned int x[25];
int i;

void init_vars() {
    m = 1; 
    a = 0x9E3779B9U;
    for (int j = 0; j < 25; j++) {
        x[j] = j * 101; 
    }
}

void loop(); 

__attribute__((constructor))
static void initialize() {
    init_vars();
}