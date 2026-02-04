#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern int N;
extern double mu;
extern double Ynm1;
extern double Yn;
extern double Ynp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array-like sliding window access
    // Use a small circular buffer accessed consecutively to simulate state evolution
    double window[3];
    window[0] = Ynm1;
    window[1] = Yn;

    for (n = 1; n <= N; n++) {
        int prev2 = (n - 1) % 3;
        int prev1 = n % 3;
        int curr  = (n + 1) % 3;

        window[curr] = 2. * (mu + n) / x * window[prev1] - window[prev2];
    }

    // Map final window values back to output variables based on parity of N
    if (N % 2 == 0) {
        Ynp1 = window[(N + 1) % 3];
        Yn = window[N % 3];
        Ynm1 = window[(N - 1) % 3];
    } else {
        Ynp1 = window[(N + 1) % 3];
        Yn = window[N % 3];
        Ynm1 = window[(N - 1) % 3];
    }
}
