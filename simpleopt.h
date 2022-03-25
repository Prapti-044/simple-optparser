#ifndef SIMPLEOPT
#define SIMPLEOPT


#include <iostream>

#include <signal.h>

#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>

#include <CodeObject.h>
#include <Function.h>
#include <InstructionDecoder.h>
#include <Symtab.h>

#include <json.hpp>
#include "includes/cxxopts.hpp"

extern "C" {
    int decode(std::string);
    nlohmann::json printParse();
    std::string printParseString();
    std::string writeDOT();
    int hello(std::string);
}

#endif