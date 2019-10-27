#include "BlockChain.h"


int main() {
    BlockChain bChain = BlockChain(2);
 
    
    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1 Data", SupplyChain("Beans",6,"Don Juan")));
 
    SupplyChain sc("Sugar",55,"Don Carlos");
    
    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data", sc));
 
    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data", SupplyChain("Apples",87,"Don Jorge")));   

    return 0;
}

