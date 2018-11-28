/*
 * PassC2Visitor.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: deric
 */

#include <iostream>
#include <string>

#include "PassC2Visitor.h"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

PassC2Visitor::PassC2Visitor(ostream& j_file)
    : program_name(""), j_file(j_file)
{
}

PassC2Visitor::~PassC2Visitor() {}


