## How to build and run using CMake in Linux:
### Polynom project
1 - Inside polynom directory: \
`$ mkdir build`\
`$ cd build/`\
`$ cmake .S ../ -B .`\
`$ make`\
`$ ./polynom`

## How to build and run using gcc on command line in Linux:
### Polynom project
1 - First, on main.c file, change #include <polynom.h> by #include "lib/polynom.h" \
2 - Commands: \
`$ gcc -c lib/polynom.c`\
`$ gcc main.c polynom.o -o app.out -lm`\
`$ ./polynom`

