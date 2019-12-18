/* Copyright (C) Eric Dybsand, 2001. 
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright (C) Eric Dybsand, 2001"
 */
// FuSMstate.cpp: implementation of the FuSMstate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GameGems.h"
#include "FuSMstate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// DoTransition() - accept an input value and consider it within the
// state's membership range, and if within, set both value and degree
// of membership within this fuzzy state that said value represents,
// returning true if a member or false if not
//////////////////////////////////////////////////////////////////////

bool FuSMstate::DoTransition( int iInputValue )
{
	if (m_iLowRange <= iInputValue && iInputValue <= m_iHighRange)
	{

		m_iDegreeOfMembership =  this->membership->GetMembership(iInputValue);
		return true;
	}
	// the input is not in membership with this state
	m_iValueOfMembership = 0;
	m_iDegreeOfMembership = 0;
	return false;

}

//////////////////////////////////////////////////////////////////////
// GetMembershipRanges() - access ranges of membership
//////////////////////////////////////////////////////////////////////

void FuSMstate::GetMembershipRanges( int& iLow, int& iHigh )
{
	iLow = m_iLowRange;
	iHigh = m_iHighRange;

}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FuSMstate::FuSMstate( int iStateID, int iLowRange, int iHighRange, std::string membershipType )
{
	m_iStateID = iStateID;
	m_iLowRange = iLowRange;	// range of int values to represent membership in this state
	m_iHighRange = iHighRange;

	m_iValueOfMembership = 0;	// zeros indicate this state is not a supporting a membership
	m_iDegreeOfMembership = 0;	// at this time

	if (membershipType == "Linear") {
		this->membership = new LinearMembership(std::vector<int>{iLowRange, iHighRange});
	}
	else if (membershipType == "Triangular") {
		this->membership = new TriangularMembership(std::vector<int>{iLowRange, iHighRange - (iHighRange - iLowRange) / 2, iHighRange});
	}
	else if (membershipType == "Trapezoidal") {
		ASSERT(false); //just crash
	}
	else {
		ASSERT(false); //just crash
	}
}

FuSMstate::~FuSMstate()
{
	// just do something
	m_iStateID = 0;
	m_iLowRange = 0;	// range of int values to represent membership in this state
	m_iHighRange = 0;
	m_iValueOfMembership = 0;
	m_iDegreeOfMembership = 0;
}
