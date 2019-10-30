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

}

//////////////////////////////////////////////////////////////////////
// GetMembershipRanges() - access ranges of membership
//////////////////////////////////////////////////////////////////////

void FuSMstate::GetMembershipRanges( int& iLow, int& iHigh )
{

}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FuSMstate::FuSMstate( int iStateID, int iLowRange, int iHighRange )
{
	m_iStateID = iStateID;
	m_iLowRange = iLowRange;	// range of int values to represent membership in this state
	m_iHighRange = iHighRange;

	m_iValueOfMembership = 0;	// zeros indicate this state is not a supporting a membership
	m_iDegreeOfMembership = 0;	// at this time
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
