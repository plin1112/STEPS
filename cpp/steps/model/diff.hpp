////////////////////////////////////////////////////////////////////////////////
// STEPS - STochastic Engine for Pathway Simulation
// Copyright (C) 2005-2008 Stefan Wils. All rights reserved.
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
// $Id$
////////////////////////////////////////////////////////////////////////////////

#ifndef STEPS_MODEL_DIFF_HPP
#define STEPS_MODEL_DIFF_HPP 1

// Autotools definitions.
#ifdef HAVE_CONFIG_H
#include <steps/config.h>
#endif

// STL headers.
#include <cassert>
#include <string>
#include <map>
#include <vector>

// STEPS headers.
#include <steps/common.h>

////////////////////////////////////////////////////////////////////////////////

START_NAMESPACE(steps)
START_NAMESPACE(model)

////////////////////////////////////////////////////////////////////////////////

// Forward declarations.
class Diff;
class Volsys;
class Model;
class Spec;

// Auxiliary declarations.
typedef Diff *						    DiffP;
typedef std::map<std::string, DiffP>    DiffPMap;
typedef DiffPMap::iterator              DiffPMapI;
typedef DiffPMap::const_iterator        DiffPMapCI;
typedef std::vector<DiffP>              DiffPVec;
typedef DiffPVec::iterator              DiffPVecI;
typedef DiffPVec::const_iterator        DiffPVecCI;

////////////////////////////////////////////////////////////////////////////////
/// Diffusion rule in a volume system.
/// 
///\warning Methods start with an underscore are not exposed to Python.

class Diff
{

public:

	////////////////////////////////////////////////////////////////////////
	// OBJECT CONSTRUCTION & DESTRUCTION
	////////////////////////////////////////////////////////////////////////
    
    /// Constructor
    ///
    /// \param id ID of the difusion rule.
    /// \param volsys Volume system which the diffusion rule belongs to.
    /// \param lig Pointers to the species which the diffusion applies to.
    /// \param dcst Rate constant of the diffusion rule.
	Diff(std::string const & id, Volsys * volsys, Spec * lig, double dcst=0.0);

    /// Destructor
	~Diff(void);

	////////////////////////////////////////////////////////////////////////
	// DIFFUSION RULE PROPERTIES
	////////////////////////////////////////////////////////////////////////

	/// Return the diffusion rule ID.
    ///
    /// \return ID of the diffusion rule.
	std::string getID(void) const
	{ return pID; }

    /// Set the ID of the diffusion rule.
    ///
    /// \param id ID of the diffusion rule.
	void setID(std::string const & id);

	/// Return a pointer to the parent volume system.
    ///
    /// \return Pointer to the parent volume system.
	Volsys * getVolsys(void) const
	{ return pVolsys; }

	/// Return a pointer to the parent model.
    ///
    /// \return Pointer to the parent model.
	Model * getModel(void) const
	{ return pModel; }

	////////////////////////////////////////////////////////////////////////
	// OPERATIONS (EXPOSED TO PYTHON):
	////////////////////////////////////////////////////////////////////////

	/// Return a pointer to the species to which this diffusion rule applies
    ///
    /// \return Pointer of the species
	Spec * getLig(void) const
	{ return pLig; }

    /// Set the species which this difusion rule applies to.
    ///
    /// \param lig Pointer to the species
	void setLig(Spec * lig);

    /// Get the rate constant of the diffusion rule.
    ///
    /// \return Rate constant of the diffusion rule.
	double getDcst(void) const
	{ return pDcst; }

    /// Set the rate constant of the diffusion rule.
    ///
    /// \param Rate constant of the diffusion rule.
	void setDcst(double dcst);

	///  Return a list of all species in this diffusion rule.
	///
    /// \return List of pointers of species.
    /// \warning Currently will return only one species.
	std::vector<Spec *> getAllSpecs(void) const;

	////////////////////////////////////////////////////////////////////////
	// INTERNAL (NON-EXPOSED) OPERATIONS: DELETION
	////////////////////////////////////////////////////////////////////////

    /// Self delete.
    ///
	/// Called if Python object deleted, or from del method in parent object.
	/// Will only be called once
	void _handleSelfDelete(void);

	////////////////////////////////////////////////////////////////////////

private:

	////////////////////////////////////////////////////////////////////////

	std::string                         pID;
	Model                             * pModel;
	Volsys                            * pVolsys;
	Spec                              * pLig;
	double                              pDcst;

	////////////////////////////////////////////////////////////////////////

};

////////////////////////////////////////////////////////////////////////////////

END_NAMESPACE(model)
END_NAMESPACE(steps)

#endif
// STEPS_MODEL_DIFF_HPP

// END
