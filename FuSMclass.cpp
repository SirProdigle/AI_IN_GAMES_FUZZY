/* Copyright (C) Eric Dybsand, 2001. 
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright (C) Eric Dybsand, 2001"
 */
// FuSMclass.cpp: implementation of the FuSMclass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GameGems.h"
#include "FuSMclass.h"
#include "FuSMstate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// StateTransition() - perform fuzzy state transitions, based on input
// and membership ranges of states in the map.  Since the FuSM can be
// in membership with multiple fuzzy states at any given time, another
// process is needed to review current membership states
//////////////////////////////////////////////////////////////////////

void FuSMclass::StateTransition( int iInput )
{
	FuSMstate *pState = NULL;
	FuzzyState_List::iterator itL;
	FuzzyState_Map::iterator itM;

	// first clear the membership list

	// accumulate value received, so that input is persistent,
	// and triggers transitions to new membership fuzzy states

	// in this design of an FuSM, we are only allowing positive values
	// to effect transistions, however this is not a limit of FuSMs
	if( m_iCurrentInput < 0 )
		m_iCurrentInput = 0;
	if( m_iCurrentInput > 100 )
		m_iCurrentInput = 100;

	// now iterate through the fuzzy state map using the current input value

	// now the m_list contains pointers to all fuzzy states in which membership exists
	// so set the internal iterator to point to the begining of the list so that we
	// can iterate through the active states later on using GetNextFuzzyStateMember()
}

//////////////////////////////////////////////////////////////////////
// GetNextFuzzyStateMember() - provide access to the member states in
// the FuzzyState_List
//////////////////////////////////////////////////////////////////////

FuSMstate *FuSMclass::GetNextFuzzyStateMember(void)
{
	// if the list is empty, or the iterator is pointing to the end
	// of the list then return a NULL to signal the end has been reached

	// get the pointer to the FuSMstate object that is currently
	// pointed to by the iterator

	// go to the next pointer in the list
	
	// and return the one pointer we found
}

//////////////////////////////////////////////////////////////////////
// GetState() - return the FuSMstate object pointer referred to by the
// state ID passed
//////////////////////////////////////////////////////////////////////

FuSMstate *FuSMclass::GetState( int iStateID )
{
}

//////////////////////////////////////////////////////////////////////
// AddState() - add a FuSMstate object pointer to the map
//////////////////////////////////////////////////////////////////////

void FuSMclass::AddState( FuSMstate *pNewState )
{

}

//////////////////////////////////////////////////////////////////////
// DeleteState() - delete a FuSMstate object pointer from the map
//////////////////////////////////////////////////////////////////////

void FuSMclass::DeleteState( int iStateID )
{

}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FuSMclass::FuSMclass()
{
	m_iCurrentInput = 0;	// value received that triggered transitions to new membership fuzzy states
}

FuSMclass::~FuSMclass()
{
	FuSMstate *pState = NULL;
	FuzzyState_Map::iterator it;

	// only perform this if there are pointers in the map
	if( !m_map.empty() )
	{
		// first delete any FuSMstate objects in the map
		for( it = m_map.begin(); it != m_map.end(); ++it )
		{
			pState = (FuSMstate *)((*it).second);
			if( pState != NULL )
				delete pState;
		}
		// let the m_map dtor() erase the actual pointer out of the map
	}
	// let the m_list dtor() erase the actual pointer out of the list
}

// end of FuSMclass.cpp