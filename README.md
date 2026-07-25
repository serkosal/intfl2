# intfl2
interactive file listing utility 2

# build
cd build
cmake .. -DCMAKE_GENERATOR=Ninja -DFTXUI_BUILD_MODULES=ON -B .
ninja -j$(nproc)

UI: ftxui 
fswatch: for file updates https://github.com/emcrisostomo/fswatch
file scanning and ui updates in different threads
