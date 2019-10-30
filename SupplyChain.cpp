#include "SupplyChain.h"
#include <sstream>

//linea para compilar windows
#pragma warning(disable : 4996)

SupplyChain::SupplyChain(string productName, unsigned int invoiceQuantity, string provider) :
                        productName(productName), 
                        invoiceQuantity(invoiceQuantity), 
                        provider(provider){
    arrivalDate = time(0);
}

SupplyChain::SupplyChain(){}


string SupplyChain::toString() const{
    stringstream ss;
    ss << productName<< invoiceQuantity << arrivalDate << provider;
    
    return ss.str();
}

void SupplyChain::showInformation(){
    cout << "Product's name:" << productName << endl;
    cout << "Quantity:" << invoiceQuantity << endl;
    cout << "Arrival date: " << ctime(&arrivalDate);
    cout << "Provider:" << provider << endl << endl;
}