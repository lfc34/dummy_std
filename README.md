# Dummy STD

**It's a studying project. Use this code with caution.** \

The goal is to reimplement all C standard library (except for macro only libs, because it's stupid, but maybe I'll do them one day), without using anything except for regular C (no dependencies, no std, only pure C language)

For now it's only targeted for unix like platforms (Linux, BSD, MacOS).

## Roadmap
- <assert.h> - **IMPLEMENTED ✅** 
- <ctype.h> - **IMPLEMENTED ✅**
- <math.h> - **IN PROCESS 🚧**
- <string.h> - **IMPLEMENTED PARTIALLY ⚠️**
- <stdlib.n> - **IN PROCESS 🚧**

## How to build and use
```bash
git clone https://github.com/lfc34/dummy_std.git
cd dummy_std
make static # for static library (.a)
make shared # for shared library (.so)
```

If you made static version, you can simply point compiler to headers and link it at compile stage.
```bash
cc main.c -Iinclude/ -L. -ldummy_std -o main
```
Where 'include/' and '.' are locations of where dummy_std headers lie and dummy_std.a file is located respectively. 