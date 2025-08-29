# Dummy STD
For now it's only targeted for *nix like platforms.

The goal is to reimplement all C standard library, without using anything except for regular C (no dependencies, no std, only pure C language)

## Roadmap
- <assert.h> - **IMPLEMENTED ✅** 
- <ctype.h> - **IMPLEMENTED ✅**
- <string.h> - **IMPLEMENTED PARTIALLY ⚠️**
- <stdlib.n> - **IN PROCESS 🚧**

## How to build
```bash
make static # for static library (.a)
make shared # for shared library (.so)
```