#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "StringTiePlugin.h"

void StringTiePlugin::input(std::string file) {
   readParameterFile(file);
}

void StringTiePlugin::run() {}

void StringTiePlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 if (myParameters.count("merge") != 0) {
    myCommand += "stringtie --merge -p 6 -G "+PluginManager::addPrefix(myParameters["gfffile"])+" -o "+file+" "+PluginManager::addPrefix(myParameters["txtfile"]);
 }
 else if (myParameters.count("estimate") != 0) {
    myCommand += "stringtie -e -B -p 8 -G "+PluginManager::addPrefix(myParameters["gtffile"])+" -o "+file+" "+PluginManager::addPrefix(myParameters["bamfile"]);
 }
 else {
    myCommand += "stringtie -p 6 -G "+PluginManager::addPrefix(myParameters["gfffile"])+" -o "+file+" -l "+myParameters["name"]+" "+PluginManager::addPrefix(myParameters["bamfile"]);
 }
 //stringtie -p 6 -G Homo_sapiens.GRCh38.87.gff3 -o assembl/S12_R1.gtf -l S12_R1 align/bam/S12_R1.bam
//stringtie -p 6 -G Homo_sapiens.GRCh38.87.gff3 -o assembl/S12_R2.gtf -l S12_R2 align/bam/S12_R2.bam
//stringtie --merge -p 6 -G Homo_sapiens.GRCh38.87.gff3 -o merged/stringtie_merged.gtf merged/mergelist.txt
//stringtie -e -B -p 8 -G merged/stringtie_merged.gtf -o merged/counts/S12_R1/S12_R1.gtf align/bam/S12_R1.bam
//stringtie -e -B -p 8 -G merged/stringtie_merged.gtf -o merged/counts/S12_R2/S12_R2.gtf align/bam/S12_R2.bam

 //myCommand += "hisat2 -p 6 --dta -x "+PluginManager::addPrefix(myParameters["database"])+" -q "+PluginManager::addPrefix(myParameters["fastq"])+" -S "+file;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<StringTiePlugin> StringTiePluginProxy = PluginProxy<StringTiePlugin>("StringTie", PluginManager::getInstance());
