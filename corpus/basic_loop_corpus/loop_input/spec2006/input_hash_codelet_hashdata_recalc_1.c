#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char Intersection;
typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

Intersection board[421];
Hashvalue white_hash[400][1];
Hashvalue black_hash[400][1];
Hash_data *target;
Intersection *p;
int pos;
int i;

void init_vars() {
    const int N = 400;
    const int hash_size = 64 / (8 * sizeof(long));
    
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= N) ? 3 : rand() % 4;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < hash_size; j++) {
            white_hash[i][j] = rand();
            black_hash[i][j] = rand();
        }
    }
    
    target = (Hash_data*)malloc(sizeof(Hash_data));
    if (!target) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    p = board;
    
    for (int j = 0; j < hash_size; j++) {
        target->hashval[j] = rand();
    }
}