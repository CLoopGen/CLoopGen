#!/bin/bash
programs=(polybench npb tsvc rodinia cbench spec2006 opencv openssl openblas gsl ImageMagick redis numpy fftw ffmpeg)

for program in "${programs[@]}"; do
    python3 get_feature.py --astExec ../../build/getASTFeature --pass_path ../../build/libIRLoopFeatureExtractor.so --output features/$program.npy --input ../../corpus/basic_json/$program.json
done

for program in "${programs[@]}"; do
    python3 get_feature.py --astExec ../../build/getASTFeature --pass_path ../../build/libIRLoopFeatureExtractor.so --output features/enhanced_$program.npy --input ../../corpus/enhanced_json/$program.json
done


