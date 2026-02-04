#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
int nB = 0;
int tryA = 0;
int tryB = 0;
int rightA = 0;
int rightB = 0;
int np1_2 = 0;

void init_vars() {
    np1_2 = 300000;  // Adjusted to achieve ~0.01s runtime
    nB = 200000;     // Set nB to a large value, consistent with loop logic
    medA = 5.0;
    medB = 4.9;      // Ensure medA >= medB triggers one branch initially
}