#ifndef SUPPLYCHAIN_H
#define SUPPLYCHAIN_H
#include <iostream>
#include <ctime>


using namespace std;

class SupplyChain {
public:
    SupplyChain(string , unsigned int , string);
    SupplyChain();
    string toString() const;
    void showInformation();
    
    
private:
    string productName;
    unsigned int invoiceQuantity;
    time_t arrivalDate;
    string provider;
    
};

#endif
