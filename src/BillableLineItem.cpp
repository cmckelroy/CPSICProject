#include "BillableLineItem.h"
#include <iostream>
BillableLineItem::BillableLineItem(time_t time, string services, double cost, bool paid) : timestamp(time), descriptionOfServices(services), totalCost(cost), paid(paid)
{
}

void BillableLineItem::print()
{
    std::cout << "Cost: $" << totalCost;
    std::cout << "\nIssued at: " << timestamp;
    std::cout << "\nServices rendered: " << descriptionOfServices;
    std::cout << "\nPaid: ";
    if (paid)
        std::cout << "Yes.\n";
    else
        std::cout << "No.\n";
}
