#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;

char basis_64[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

char *str;
ssize_t len;
char *eol;
STRLEN eollen;
char *r;
unsigned char c1;
unsigned char c2;
unsigned char c3;
int chunk;

void init_vars() {
    const size_t input_size = 67108864; // 64 MB, tuned for ~0.01 sec on modern CPU with loop unrolling

    str = (char*)malloc(input_size);
    if (!str) exit(1);
    for (size_t i = 0; i < input_size; i++) {
        str[i] = (char)(i & 0xFF);
    }

    len = input_size;

    eol = (char*)malloc(2);
    if (!eol) exit(1);
    eol[0] = '\r';
    eol[1] = '\n';
    eollen = 2;

    r = (char*)malloc(input_size * 4 / 3 + 16); // Base64 expands by ~4/3, plus margin
    if (!r) exit(1);

    chunk = 0;
}