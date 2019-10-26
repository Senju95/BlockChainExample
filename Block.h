#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include "SupplyChain.h"


using namespace std;

class Block {
    
public:
    string prevHash;
    
    Block(uint32_t nIndexIn, const string &sDataIn, SupplyChain);
    string GetHash();
 
    void MineBlock(uint32_t nDifficulty);
    void showBlockInformation();
    bool hasBeenChanged();
    void setNNonce(int);
 
private:
    uint32_t nIndex;
    int64_t nNonce;
    string sData;
    string sHash;
    time_t tTime;
    SupplyChain supplyChain;
 
    string CalculateHash() const;

};

#endif 

