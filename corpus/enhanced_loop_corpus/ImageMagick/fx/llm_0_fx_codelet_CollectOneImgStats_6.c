#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ChannelStatistics {
    size_t depth;
    double area;
    double minima;
    double maxima;
    double sum;
    double sum_squared;
    double sum_cubed;
    double sum_fourth_power;
    double mean;
    double variance;
    double standard_deviation;
    double kurtosis;
    double skewness;
    double entropy;
    double median;
    long double sumLD;
    long double M1;
    long double M2;
    long double M3;
    long double M4;
} ChannelStatistics;

typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern int ch;
extern ChannelStatistics *cs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (ch = 0; ch <= (int)64; ch++) {
        cs[ch].mean *= ((double)1. / (double)((Quantum)65535.));
        cs[ch].median *= ((double)1. / (double)((Quantum)65535.));
        cs[ch].maxima *= ((double)1. / (double)((Quantum)65535.));
        cs[ch].minima *= ((double)1. / (double)((Quantum)65535.));
        cs[ch].standard_deviation *= ((double)1. / (double)((Quantum)65535.));
    }
}
}
