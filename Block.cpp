#include "Block.h"
#include "sha256.h"

//linea para compilar windows
#pragma warning(disable : 4996)

//constructor
Block::Block(uint32_t nIndexIn, const string &sDataIn,SupplyChain supplyChain) : nIndex(nIndexIn), sData(sDataIn) {
    nNonce = -1;
    tTime = time(nullptr);
    this->supplyChain = supplyChain;
}


//create the block's hash
inline string Block::CalculateHash() const {
    stringstream ss;
    ss << nIndex << tTime << sData << nNonce << prevHash << supplyChain.toString();
    return sha256(ss.str());
}

//simulate how a block is mined 
void Block::MineBlock(uint32_t nDifficulty) {
   /*
    *Cambio para que funcione en windows
    * hay que usar una escribir la dificultad a mano
    */ 
   char cstr[4 + 1];
    for (uint32_t i = 0; i < 4; ++i) {
        cstr[i] = '0';
    }
    cstr[4] = '\0';

 
    string str(cstr);
 
    do {
        nNonce++;
        sHash = CalculateHash();
    } while (sHash.substr(0, nDifficulty) != str);
 
    cout << endl <<"Block mined: " << sHash << endl;
}


//returns block's hash
string Block::GetHash() {
    return sHash;
}

//Show information of the block
void Block::showBlockInformation(){
    cout <<"Previous block's hash code:" << prevHash<< endl;
    cout << "Time stamp:" << ctime(&tTime) << endl;
    cout << "SupplyChain information:" << endl; 
    supplyChain.showInformation();
}


bool Block::hasBeenChanged(){
    return sHash != CalculateHash();
}

void Block::setSupplyChain(SupplyChain newSupply){
    this->supplyChain = newSupply;
}