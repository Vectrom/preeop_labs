#pragma once

class Person {

	typedef bool (*sortType)(const Person&, const Person&);

public:

	Person(const std::string name, const int & age); 

	void print() const;

	static bool byName(const Person& p1, const Person& p2); 

	static bool byID(const Person& p1, const Person& p2);

	void swapID(const Person * p) const;

	static const Person ** sort(const Person ** from, const Person ** to, sortType type);

	operator std::string() const;
	
private:
	const std::string _name;
	const int _age;
	mutable int _ID;
	static int _lastID;
};