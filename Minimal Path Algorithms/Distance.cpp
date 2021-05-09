#include "Distance.h"
bool Distance::operator>(const Distance& other)const {
	if (this->infinity) {
		if (other.infinity)
			return false;
		else
			return true;
	}
	else {// infinity = false
		if (other.infinity)
			return false;
		else
			return this->value > other.value;
	}
}
bool Distance::operator>(const int& num)const {
	if (infinity)
		return true;
	else
		return value > num;
}
