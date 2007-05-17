////////////////////////////////////////////////////////////////////////////////
// STEPS - STochastic Engine for Pathway Simulation
// Copyright (C) 2005-2007 Stefan Wils. All rights reserved.
//
// $Id$
////////////////////////////////////////////////////////////////////////////////

// STL headers.
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// STEPS headers.
#include <steps/common.h>
#include <steps/math/constants.hpp>
#include <steps/rng/rng.hpp>
#include <steps/sim/shared/compdef.hpp>
#include <steps/sim/shared/reacdef.hpp>
#include <steps/sim/shared/specdef.hpp>
#include <steps/sim/shared/statedef.hpp>
#include <steps/sim/swiginf/func_ssa.hpp>
#include <steps/sim/wmdirect/state.hpp>

////////////////////////////////////////////////////////////////////////////////

double siStep(State * s)
{
}

////////////////////////////////////////////////////////////////////////////////

uint siGetNSteps(State * s)
{
    assert(s != 0);
    return s->fNSteps;
}

////////////////////////////////////////////////////////////////////////////////

double siGetA0(State * s, uint cidx, uint ridx)
{
    return 0.0;
}

////////////////////////////////////////////////////////////////////////////////

double siGetCompReacC(State * s, uint cidx, uint ridx)
{
    return 0.0;
}

////////////////////////////////////////////////////////////////////////////////

double siGetCompReacH(State * s, uint cidx, uint ridx)
{
    return 0.0;
}

////////////////////////////////////////////////////////////////////////////////

double siGetCompReacA(State * s, uint cidx, uint ridx)
{
    return 0.0;
}

////////////////////////////////////////////////////////////////////////////////

uint siGetCompReacExtent(State * s, uint cidx, uint ridx)
{
    return 0;
}

////////////////////////////////////////////////////////////////////////////////

uint siResetCompReacExtent(State * s, uint cidx, uint ridx)
{
    return 0;
}

////////////////////////////////////////////////////////////////////////////////

// END
