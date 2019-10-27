/*
 *https://davenash.com/2017/10/build-a-blockchain-with-c/
 */

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
	
#include <cstdint>
#include <vector>
#include "Block.h"
 
using namespace std;

class BlockChain {
    
public:
    BlockChain(int);
    void AddBlock(Block bNew);
    
    //Para el taller
    //bool verifyChain();
    //Block& getBlock(int);
private:
    uint32_t difficulty;
    vector<Block> chain;
 
    Block GetLastBlock() const;
    //Block getBlock(int);

};

#endif

