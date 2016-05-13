# StringObfuscator
Compile-time obfuscation of strings (C++11)
# Example
```c++
#include <iostream>
#include "str_obfuscator.hpp"

using namespace std;

void main(void)
{
	cout << cryptor::create("Hello, World!").decrypt() << endl;

	cin.get();
}
```
