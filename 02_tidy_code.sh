clang-tidy -p build main.cpp -checks='google-*,clang-analyzer-*,modernize-*' -header-filter='.*' -- -I/usr/include/c++/11 -I/usr/include/x86_64-linux-gnu/c++/11 -I/usr/include
