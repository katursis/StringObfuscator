# StringEncryptor
Compile-time encryption of string's (C++11)
# Example
```c++
#include <iostream>
#include "str_encryptor.hpp"

using namespace std;

void main(void)
{
	cout << cryptor::create("Hello, World!").decrypt() << endl;

	cin.get();
}
```
