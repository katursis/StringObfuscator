# StringObfuscator
Compile-time string obfuscation (C++11)

## Requirements
- VS 2015
- /O2 compiler flag

## Example
```c++
#include <iostream>
#include "str_obfuscator.hpp"

using namespace std;

void main(void)
{
	cout << cryptor::create("Hello, World!").decrypt() << endl;
}
```
