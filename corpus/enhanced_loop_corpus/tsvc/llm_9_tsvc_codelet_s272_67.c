#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        if (e[i] >= t && e[i+16000] >= t) {
            a[i] += c[i] * d[i] + c[i] * c[i];
            b[i] += c[i] * d[i] * 0.5f;
            a[i+16000] += c[i+16000] * d[i+16000] + d[i+16000] * d[i+16000];
            b[i+16000] += c[i+16000] * c[i+16000] * 0.5f;
        } else if (e[i] >= t) {
            a[i] += c[i] * d[i];
            b[i] += c[i] * c[i];
        } else if (e[i+16000] >= t) {
            a[i+16000] += c[i+16000] * d[i+16000];
            b[i+16000] += c[i+16000] * c[i+16000];
        }
    }
}
}
