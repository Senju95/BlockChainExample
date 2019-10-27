#include "BlockChain.h"
#include <stdexcept>

	
//constructor
BlockChain::BlockChain(int nDifficulty) : difficulty(nDifficulty){
    //Add the genesis block
    chain.emplace_back(Block(0, "Genesis Block", SupplyChain("Genesis",0,"Doña Melissa")));
}

//return the last block of the chain
Block BlockChain::GetLastBlock() const {
    return chain.back();
}

//add a new block to the chain
void BlockChain::AddBlock(Block bNew) {
    bNew.prevHash = GetLastBlock().GetHash();
    bNew.MineBlock(difficulty);
    bNew.showBlockInformation();
    chain.push_back(bNew);
}



