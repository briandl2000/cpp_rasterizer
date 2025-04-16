@echo off
:: Configure Release build
cmake -S . -B build/Release -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=%cd%/build/bin
:: Build Release configuration
cmake --build build/Release
