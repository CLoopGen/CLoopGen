#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern double *data;
extern int data_len;
extern int j;
extern complex *IN;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < data_len; j++) {
    IN[j].r = data[j];
    IN[j].i = 0.;
}

}
