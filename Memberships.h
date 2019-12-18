#pragma once
#include <vector>
#include "StdAfx.h"

//vector of ints are arguments, varied length based on function
class FuzzyMembership {
protected :
	std::vector<int> params;

	FuzzyMembership() {}

	FuzzyMembership(std::vector<int> p) {
		params = p;
	}
	
public:
	virtual int GetMembership(int) = 0;
	static int interpolate(float a, float b, float percentage) {
		return a + percentage * (b - a);
	}
};

class LinearMembership : public FuzzyMembership {
public:
	LinearMembership(std::vector<int> p) {
		params = p;
	}

	virtual int GetMembership(int amount) {
		int m_iValueOfMembership = (amount - params[0]) + 1;
		int degrees = 0;
		if (params[1])
			degrees = ((m_iValueOfMembership * 100) / params[1]);
		else
			degrees = 0;


		// handle odd case of a crisp fuzzy range of a single value
		if (m_iValueOfMembership == 1 && params[0] == params[1])
			degrees = 100;
		
		return degrees;
	}
};
//params 1 = low
//params 2 = mid
//param 3 = high
class TriangularMembership : public FuzzyMembership {
public:
	TriangularMembership(std::vector<int> p) {
		params = p;
	}

	virtual int GetMembership(int amount) {
		int low = params[0];
		int mid = params[1];
		int high = params[2];

		if (amount > low && amount <= mid) {
			int degree = FuzzyMembership::interpolate(0, 100, (((float)amount - low) / ((float)mid - low))  );
			return degree;
		}
		else if (amount > mid && amount <= high) {
			int degree = FuzzyMembership::interpolate(100, 0, (((float)amount - mid) / ((float)high - mid)) );
			return degree;
		}
		else {
			return 0;
		}
	}
};

class TrapezoidalMembership : public FuzzyMembership {
public:
	virtual int GetMembership(int amount) {
		ASSERT(false); //Placeholder
	}
};