#!/bin/bash
cd ..

cache_path=buildcache
output_path=output
test_exe=Executable
exe_suffix=""

if [ ! -d buildcache ]; then
    mkdir buildcache
fi

rm -rf ${cache_path}/*

rm -rf ${output_path}
rm -rf ${release_path}

os=$(uname -s)
os=${os%_*}
if [[ ${os} == "MINGW"* ]]; then
    cmake -S . -B ${cache_path}  -G "MinGW Makefiles"
    exe_suffix=".exe"
else
    cmake -S . -B ${cache_path}
fi
cmake --build ${cache_path}

./${output_path}/${test_exe}${exe_suffix}
