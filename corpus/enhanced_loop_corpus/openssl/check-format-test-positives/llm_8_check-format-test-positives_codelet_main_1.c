#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t sum = 0;
    for (int i = 0; i < n * n; i++) {
        sum += i * i + 3 * i - 5;
        if (sum > 1000000) break;
    }
    n += sum % 100;
}
