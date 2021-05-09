#pragma once
class Distance
{
public:
	int value;
	bool infinity;
	Distance() :value(0), infinity(true) {}
	Distance(const int& num) :value(num), infinity(false) {}

	void operator=(const int& num) { value = num; infinity = false; }
	bool operator>(const Distance& other)const;
	bool operator>(const int& num)const;
	bool operator==(const Distance& other)const { 
		return value == other.value && infinity == other.infinity; 
	}
	Distance operator+(const int& num)const {
		if (infinity) {
			return Distance();
		}
		else {
			return Distance(value + num);
		}
	}
};

