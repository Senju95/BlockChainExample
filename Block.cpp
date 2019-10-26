#include "Block.h"
#include "sha256.h"


Block::Block(uint32_t nIndexIn, const string &sDataIn,SupplyChain supplyChain) : nIndex(nIndexIn), sData(sDataIn) {
    nNonce = -1;
    tTime = time(nullptr);
    this->supplyChain = supplyChain;
}



inline string Block::CalculateHash() const {
    stringstream ss;
    ss << nIndex << tTime << sData << nNonce << prevHash << supplyChain.toString();
    return sha256(ss.str());
}

void Block::MineBlock(uint32_t nDifficulty) {
   char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

 
    string str(cstr);
 
    do {
        nNonce++;
        sHash = CalculateHash();
    } while (sHash.substr(0, nDifficulty) != str);
 
    cout << endl <<"Block mined: " << sHash << endl;
}


string Block::GetHash() {
    return sHash;
}

void Block::showBlockInformation(){
    cout <<"Previous block's hash code:" << prevHash<< endl;
    cout << "Time stamp:" << ctime(&tTime) << endl;
    cout << "Supplychain information:" << endl; 
    supplyChain.showInformation();
    
}


bool Block::hasBeenChanged(){
    return sHash != CalculateHash();
}

void Block::setNNonce(int value){
    this->nNonce = value;
}