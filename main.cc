// main.cc - Simple spam filter application
#include <iostream>
#include <string>

#include "spamfilter.h"

int main()
{
    SpamFilter* sf = new SpamFilter();
    std::string src = "../src.txt";
    std::string tgt = "../tgt.txt";

    std::string* blklst = new std::string[10];

    blklst[0] = "computer";
    blklst[1] = "programming";
    blklst[2] = "hacker";
    blklst[3] = "C++";
    blklst[4] = "security";
    blklst[5] = "system";
    blklst[6] = "google";
    blklst[7] = "algorithm";
    blklst[8] = "data";

    sf->setBlacklist(blklst);
    sf->filter(src, tgt);

    std::cout << *sf << '\n';
    
    delete sf;
    delete[] blklst;
}