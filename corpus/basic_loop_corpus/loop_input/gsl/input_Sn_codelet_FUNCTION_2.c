#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

double medA = 0.0;
double medB = 0.0;
int i = 0;
int diff = 0;
int half = 0;
int Amin = 0;
int Amax = 0;
int even = 0;
int length = 0;
int leftA = 0;
int leftB = 0;
int nA = 0;
int nB = 10000;
int tryA = 0;
int tryB = 0;
int rightA = 0;
int rightB = 0;
int np1_2 = 5000;

void init_vars() {
    srand(time(NULL));
    medA = 1.5;
    medB = 2.5;
    nB = 10000;
    np1_2 = 5000;
}