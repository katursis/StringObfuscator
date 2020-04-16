# StringObfuscator
Simple header-only compile-time string encryptor (C++14)

## Requirements
- O2 (optimization option)

## Example
```c++
#include <iostream>
#include "str_obfuscator.hpp"

int main() {
    std::cout << cryptor::create("Hello, World!").decrypt() << std::endl;

    return 0;
}
```
