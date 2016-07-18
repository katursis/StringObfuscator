# StringObfuscator
Compile-time string obfuscation (C++14)

## Requirements
- O2 (optimization option)

## Example
```c++
#include <iostream>
#include "str_obfuscator.hpp"

using namespace std;

int main(void)
{
	cout << cryptor::create("Hello, World!").decrypt() << endl;
	
	return 0;
}
```
