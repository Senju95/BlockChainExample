#include "BlockChain.h"


int main() {
    BlockChain bChain = BlockChain(5);
 
    
    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1 Data", SupplyChain("Beans",6,"Don Juan")));
 
    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data", SupplyChain("Sugar",55,"Don Carlos")));
 
    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data", SupplyChain("Apples",87,"Don Jorge")));
   
    
    cout << endl << "-------------------Test #1---------------------------";
    if(bChain.verifyChain())
        cout << endl << "The chain hasn't been modified";
    else 
        cout << endl << "The chain has been modified";
    
    
    cout << endl << "--------------------Test #2--------------------------";
    bChain.getBlock(3).setNNonce(35);
            
    if(bChain.verifyChain())
        cout << endl << "The chain hasn't been modified";
    else 
        cout << endl << "The chain has been modified";

    return 0;
}

