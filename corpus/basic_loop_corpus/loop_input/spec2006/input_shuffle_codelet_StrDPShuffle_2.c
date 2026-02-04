#include <stdio.h>
#include <inttypes.h>

int x;
int *nE;
char sf;
char Z[26];
int is_eulerian;

static int nE_data[26];

void init_vars() {
    x = 0;
    sf = 5; 
    is_eulerian = 1;

    for (int i = 0; i < 26; i++) {
        nE_data[i] = (i % 7) + 1;
        Z[i] = (i % 3) ? 0 : 1;
    }
    nE = nE_data;
}