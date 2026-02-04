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
for (ch = 0; ch <= (int)32; ch += 2) {
    double invQuantum = (double)1. / (double)((Quantum)65535.);
    long double scaleLD = (long double)1. / (long double)((Quantum)65535.);
    cs[ch].mean *= invQuantum;
    cs[ch].median *= invQuantum;
    cs[ch].maxima *= invQuantum;
    cs[ch].minima *= invQuantum;
    cs[ch].standard_deviation *= invQuantum;
    cs[ch].M1 *= scaleLD;
    cs[ch].M2 *= scaleLD * scaleLD;
    cs[ch].M3 *= scaleLD * scaleLD * scaleLD;
    cs[ch + 1].mean *= invQuantum;
    cs[ch + 1].median *= invQuantum;
    cs[ch + 1].maxima *= invQuantum;
    cs[ch + 1].minima *= invQuantum;
    cs[ch + 1].standard_deviation *= invQuantum;
}
}
