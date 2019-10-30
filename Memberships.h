#pragma once
#include <vector>
#include "StdAfx.h"

//vector of ints are arguments, varied length based on function
class FuzzyMembership {
	virtual int GetMembership(std::vector<int>) = 0;
};

class TriangularMembership : FuzzyMembership {
	virtual int GetMembership(std::vector<int> args) {

	}
};
class TrapezoidalMembership : FuzzyMembership {
	virtual int GetMembership(std::vector<int> args) {
		return 60;
	}
};