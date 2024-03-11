#ifndef StringTiePLUGIN_H
#define StringTiePLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class StringTiePlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "StringTie";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
