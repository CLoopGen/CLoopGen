#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 131072

int **pam;
char buf1[61];
char bufmid[61];
char buf2[61];
int count1;
int count2;
int apos;

void init_vars() {
    pam = (int**)calloc(26, sizeof(int*));
    for (int i = 0; i < 26; ++i) {
        pam[i] = (int*)calloc(26, sizeof(int));
        for (int j = 0; j < 26; ++j) {
            pam[i][j] = (i == j) ? 2 : -1;
        }
    }

    for (int i = 0; i < 60; ++i) {
        buf1[i] = "ACGT-N~."[rand() % 8];
        buf2[i] = "ACGT-N~."[rand() % 8];
    }
    buf1[60] = '\0';
    buf2[60] = '\0';

    memset(bufmid, 0, sizeof(bufmid));

    count1 = 60;
    count2 = 60;
}