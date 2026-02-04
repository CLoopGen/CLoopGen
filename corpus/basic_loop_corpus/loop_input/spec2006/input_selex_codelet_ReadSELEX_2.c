#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **aseqs;
int num = 65536;
int seqidx;
int alen = 128;

void init_vars() {
    aseqs = (char **)calloc(num, sizeof(char *));
    if (!aseqs) {
        fprintf(stderr, "Failed to allocate aseqs\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        aseqs[i] = (char *)malloc((alen + 1) * sizeof(char));
        if (!aseqs[i]) {
            fprintf(stderr, "Failed to allocate aseqs[%d]\n", i);
            exit(1);
        }
        memset(aseqs[i], 'A', alen);
        aseqs[i][alen] = '\xFF'; 
    }
}