# CLoopGen

 ## Install LLVM22

```bash
git clone https://github.com/llvm/llvm-project.git
git checkout f8b5f86cd9c1
mkdir build 
cd build 
cmake  -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra"  -DLLVM_ENABLE_RTTI=ON  -DCMAKE_INSTALL_PREFIX=./ -DBUILD_SHARED_LIBS=ON  ../llvm
make -j N
make install
```

## Install CLoopGen

```bash
git clone https://github.com/CLoopGen/CLoopGen.git
mkdir build & cd build
cmake -DLLVM_LIB_DIR=/path/to/llvm/build/lib ../src/
make
```

## Directory Structure

- corpus : A loop corpus extracted and enhanced from real programs,including OpenCV, OpenSSL, OpenBLAS, GSL, ImageMagick, Redis ...
- example :  Demonstrates the loop extraction and enhancement workflow using NumPy as a case study.
- experiment : Experimental results
- scripts : Utility scripts for variable initialization and loop enhancement
- src :  Core implementation for loop extraction and  feature extraction 

## RQ1

```bash
# Extract and enhance loops from NumPy
cd example
bash get_numpy_loops.py

# Execution time distribution
cd experiment/RQ1
python statical_time.py
```

*Note: The full loop corpus used in the paper is provided in `corpus`.*

## RQ2

```bash
# Feature Coverage Analysis
cd experiment/RQ2
bash get_all_programs_features.sh
python3 get_distribution.py
```

## RQ3

### Loop Unrolling Factor Prediction(MLoop)

- Environment Setup https://github.com/zhengzhch/mLoop.git
- Replace the original training data with our corpus  `corpus/`

### Loop Vectorization Factor Prediction(Neuro-Vectorizer)

- Environment Setup https://github.com/intel/neuro-vectorizer.git
- Replace the original training data with our corpus `corpus/`

