////////////////////////////////////////////////////////////////////////////////
// STEPS - STochastic Engine for Pathway Simulation
// Copyright (C) 2005-2007 Stefan Wils. All rights reserved.
//
// This file is part of STEPS.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA
//
// $Id:tet.hpp 64 2007-08-20 06:25:41Z stefan $
////////////////////////////////////////////////////////////////////////////////

#ifndef STEPS_TETEXACT_SOLVER_CORE_COMP_HPP
#define STEPS_TETEXACT_SOLVER_CORE_COMP_HPP 1

// Autotools definitions.
#ifdef HAVE_CONFIG_H
#include <steps/config.h>
#endif

// STL headers.
#include <cassert>
#include <vector>

// STEPS headers.
#include <steps/common.h>

// Forward declarations.
class CompDef;
class Diff;
class KProc;
class Sched;

////////////////////////////////////////////////////////////////////////////////
 
class Tet
{

public:

    ////////////////////////////////////////////////////////////////////////
	// OBJECT CONSTRUCTION & DESTRUCTION
	////////////////////////////////////////////////////////////////////////
	
    /// Constructor.
	///
    Tet
    (
    	CompDef * cdef, double vol, 
    	double a0, double a1, double a2, double a3, 
    	double d0, double d1, double d2, double d3
    );
    
    /// Destructor.
    ///
    ~Tet(void);

    /// Create the kinetic processes -- to be called when all tetrahedrons 
    /// and triangles have been fully declared and connected.
    ///
    void setupKProcs(Sched * s);
    
    void setupDeps(void);
    
    void reset(void);
    
    ////////////////////////////////////////////////////////////////////////
    // GENERAL INFORMATION
    ////////////////////////////////////////////////////////////////////////
    
    inline CompDef * compdef(void) const
    { return pCompDef; }
    
    ////////////////////////////////////////////////////////////////////////
    // SHAPE & CONNECTIVITY INFORMATION.
    ////////////////////////////////////////////////////////////////////////
    
    /// Get pointer to the next neighbouring tetrahedron.
    ///
    inline Tet * nextTet(uint i) const
    { return pNextTet[i]; }
    
    /// Set pointer to the next neighbouring tetrahedron.
    ///
    void setNextTet(uint i, Tet * t);
    
    /// Get the volume.
    ///
    inline double vol(void) const
    { return pVol; }
    
    /// Get the area of an boundary triangle.
    ///
    inline double area(uint i) const
    { return pAreas[i]; }
    
    /// Get the distance to the centroid of the next neighbouring 
    /// tetrahedron. 
    ///
    inline double dist(uint i) const
    { return pDist[i]; }
    
    ////////////////////////////////////////////////////////////////////////
    // ACCESS TO SPECIES STUFF
    ////////////////////////////////////////////////////////////////////////
    
    inline uint poolCount(uint lidx) const
    { return pPoolCount[lidx]; }
    
    inline void setPoolCount(uint lidx, uint num)
    { pPoolCount[lidx] = num; }
    
    inline void incPoolCount(uint lidx, int count) const
    { pPoolCount[lidx] += count; } 
    
	inline uint poolFlags(uint lidx) const
    { return pPoolFlags[lidx]; }

    ////////////////////////////////////////////////////////////////////////
    // ACCESS TO REACTION CHANNEL STUFF
    
    //double reacKcst(uint lidx) const
    //{ return fReacStuff[lidx * REAC_LUMP_FACTOR]; }
    
    //double reacCcst(uint lidx) const
    //{ return fReacStuff[(lidx * REAC_LUMP_FACTOR) + 1]; }
    
    //double reacHcst(uint lidx) const
    //{ return fReacStuff[(lidx * REAC_LUMP_FACTOR) + 2]; }
    
    //double reacProp(uint lidx) const
    //{ return fReacStuff[(lidx * REAC_LUMP_FACTOR) + 3]; }
    
    ////////////////////////////////////////////////////////////////////////

	inline std::vector<Diff*>::const_iterator diffBegin(void) const
	{ return pDiffs.begin(); }
	
	inline std::vector<Diff*>::const_iterator diffEnd(void) const
	{ return pDiffs.end(); }
	
private:

	////////////////////////////////////////////////////////////////////////
	// GENERAL INFO
	CompDef * 					pCompDef;
	
	////////////////////////////////////////////////////////////////////////
	// CONNECTIVITY DATA
	
	Tet *						pNextTet[4];
	
	double 						pVol;
	
	double						pAreas[4];
	
	double 						pDist[4];
	
    ////////////////////////////////////////////////////////////////////////
    // SPECIES DATA

    /// Numbers of molecules -- stored as machine word integers.
    ///
    uint *                      pPoolCount;
    
    /// Flags on these pools -- stored as machine word flags.
    ///
    uint *                      pPoolFlags;
    
    ////////////////////////////////////////////////////////////////////////
    // REACTION CHANNELS
    
    //KProc **					pReacs;
    
    ////////////////////////////////////////////////////////////////////////
    // DIFFUSION RULES
    
    std::vector<Diff*>			pDiffs;
    
};

////////////////////////////////////////////////////////////////////////////////

#endif
// STEPS_TETEXACT_SOLVER_CORE_COMP_HPP

// END