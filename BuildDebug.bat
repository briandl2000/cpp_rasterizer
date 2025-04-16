@echo off
:: Configure Debug build
cmake -S . -B build/Debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=%cd%/build/bin
:: Build Debug configuration
cmake --build build/Debug
