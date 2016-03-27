#ifndef STR_ENCRYPTOR_HPP_
#define STR_ENCRYPTOR_HPP_

class cryptor
{
public:

	template<size_t S>
	class string_encryptor
	{
	public:

		constexpr string_encryptor(const char str[S])
		{
			encryptor<S - 1>::encrypt(_buffer, str);
		}

		const char *decrypt(void) const
		{
			if (_decrypted)
				return _buffer;

			for (auto &c : _buffer)
				c ^= S;

			_decrypted = true;

			return _buffer;
		}

	private:

		template<size_t index>
		struct encryptor
		{
			static constexpr void encrypt(char dest[S], const char str[S])
			{
				dest[index] = str[index] ^ S;

				encryptor<index - 1>::encrypt(dest, str);
			}
		};

		template<>
		struct encryptor<0>
		{
			static constexpr void encrypt(char dest[S], const char str[S])
			{
				dest[0] = str[0] ^ S;
			}
		};

		mutable char _buffer[S]{};
		mutable bool _decrypted = false;
	};

	template<std::size_t S>
	static constexpr auto create(const char(&str)[S])
	{
		return string_encryptor<S>(str);
	}
};

#endif // STR_ENCRYPTOR_HPP_