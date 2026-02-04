#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

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
    const int data_size = 10000;
    nB = data_size;
    np1_2 = 5000;
    medA = 1.5;
    medB = 2.5;
    i = 0;
    diff = 0;
    half = 0;
    Amin = 0;
    Amax = 0;
    even = 0;
    length = 0;
    leftA = 0;
    leftB = 0;
    tryA = 0;
    tryB = 0;
    rightA = 0;
    rightB = 0;
}