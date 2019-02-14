#pragma once

class StringWrapper{
	public:
		friend std::ostream & operator<<(std::ostream & output, const StringWrapper & string);

		friend StringWrapper operator*(const int count, const StringWrapper & string);

		StringWrapper operator*(const int count) const;
		
		StringWrapper(const char * string);
		
		~StringWrapper();

		bool operator==(const StringWrapper &string) const;

		StringWrapper operator+(const StringWrapper &string) const;

		StringWrapper & operator=(const StringWrapper& string);

	private:
	char * _string;
};