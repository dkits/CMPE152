/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */
//
//  Created by Mike Lischke on 13.03.16.
//
#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "SimpleCLexer.h"
#include "SimpleCParser.h"
#include "PassC1Visitor.h"
#include "PassC2Visitor.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

int main(int argc, const char *args[])
{
    ifstream ins;
    ins.open(args[1]);

    ANTLRInputStream input(ins);
    SimpleCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    SimpleCParser parser(&tokens);
    tree::ParseTree *tree = parser.prog();

    PassC1Visitor *pass1 = new PassC1Visitor();
    pass1->visit(tree);

    ostream& j_file = pass1->get_assembly_file();

    PassC2Visitor *pass2 = new PassC2Visitor(j_file);
    pass2->visit(tree);

    //delete tree;
    return 0;
}
