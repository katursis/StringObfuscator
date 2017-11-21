#ifndef STR_OBFUSCATOR_HPP_
#define STR_OBFUSCATOR_HPP_

namespace detail {
	template<std::size_t index>
	struct encryptor {
		static constexpr void encrypt(char *dest, const char *str, char key) {
			dest[index] = str[index] ^ key;

			encryptor<index - 1>::encrypt(dest, str, key);
		}
	};

	template<>
	struct encryptor<0> {
		static constexpr void encrypt(char *dest, const char *str, char key) {
			dest[0] = str[0] ^ key;
		}
	};
};

class cryptor {
public:
	template<std::size_t S>
	class string_encryptor {
	public:
		constexpr string_encryptor(const char str[S], int key) :
			_buffer{}, _decrypted{false}, _key{ key % 255 } {
			detail::encryptor<S - 1>::encrypt(_buffer, str, _key);
		}

		const char *decrypt(void) const {
			if (_decrypted) {
				return _buffer;
			}

			for (auto &c : _buffer) {
				c ^= _key;
			}

			_decrypted = true;

			return _buffer;
		}

	private:
		mutable char _buffer[S];
		mutable bool _decrypted;
		const char _key;
	};

	template<std::size_t S>
	static constexpr auto create(const char(&str)[S]) {
		return string_encryptor<S>{ str, S };
	}
};

#endif // STR_OBFUSCATOR_HPP_
