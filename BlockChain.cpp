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

//return false if a block in the chain has been modified
bool BlockChain::verifyChain(){
    for(int i = 1; i < chain.size(); i++){
        Block block = getBlock(i);
        if(block.hasBeenChanged())
            return false;
    }
    return true;
}

//return a specific block of the chain
Block& BlockChain::getBlock(int position){
    if(position < 1 && position >= chain.size())
        exit(1);
    return chain.at(position);
}


