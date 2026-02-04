#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

struct iupactype {
    char sym;
    char symcomp;
    char code;
    char comp;
};

struct iupactype iupac[17] = {
    {'A', 'T', 'A', 'T'},
    {'C', 'G', 'C', 'G'},
    {'G', 'C', 'G', 'C'},
    {'T', 'A', 'T', 'A'},
    {'R', 'Y', 'A', 'T'},
    {'Y', 'R', 'C', 'G'},
    {'M', 'K', 'A', 'T'},
    {'K', 'M', 'G', 'C'},
    {'S', 'S', 'G', 'C'},
    {'W', 'W', 'A', 'T'},
    {'B', 'V', 'C', 'G'},
    {'D', 'H', 'A', 'T'},
    {'H', 'D', 'C', 'G'},
    {'V', 'B', 'G', 'C'},
    {'N', 'N', 'A', 'T'},
    {'X', 'X', 'C', 'G'},
    {'Z', 'Z', 'G', 'C'}
};

char *codeseq;
int idx;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB
    codeseq = (char*)malloc(data_size);
    if (!codeseq) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memset(codeseq, 'Z', data_size - 1); // Fill with non-matching char
    codeseq[data_size - 1] = '\0'; // Null terminate

    idx = 0;
}