//
//  main.cpp
//  CS201_HW1
//
//  Created by Mertcan Bakır on 18.10.2023.
//

#include <iostream>
#include <string>

using namespace std;
int main()
{
    string company;
    double shareholders;
    double expenses;
    double income;
    double vat;
    double profit;
    double netprofit;
    double corporatetax;
    double capitalincrease;
    double share;
    
    cout << "This accounting program calculates the state taxes and dividends for the company shareholders." << endl;
    cout << "Please enter the name of the company: ";
    cin >> company;
    cout << "Please enter the gross income of " << company << ": " ;
    cin >> income;
    if(income < 1)
    {
        cout << "Invalid input for gross income (Gross Income must be greater than 0)." << endl;
        cout << "Stopping calculations...";
        return 0;
    }
    cout << "Please enter expenses of " << company << ": " ;
    cin >> expenses;
    if(expenses < 0)
    {
        cout << "Invalid input for expenses (Expenses must be greater than or equal 0)." <<endl;
        cout << "Stopping calculations...";
        return 0;
    }
    cout << "Please enter the number of shareholders: ";
    cin >> shareholders;
    if( shareholders < 1)
    {
    cout << "Invalid input for number of shareholders (Number of shareholders must be greater than or equal to 1)." << endl;
    cout << "Stopping calculations..." << endl;
        return 0;
    }
    cout << "" << endl;
    cout << "*********** " << company << " Financial Report **********" << endl;
    cout << "" << endl;
    vat = income * 0.18;
    profit = income - (vat + expenses);
    if(profit == 0)
    {
    cout << "Net Profit: " << profit << " TL. (Break Even)" << endl;
    cout << "VAT: " << vat << " TL." << endl;
    cout << "Corporate Tax: 0 TL." << endl;
    cout << "" << endl;
    cout << "Capital Increase: 0 TL." << endl;
    cout << shareholders << " shareholders will have a share of: 0 TL." << endl;
    return 0;
    }
    if(profit < 0)
    {
    cout << "Net Loss: " << profit << " TL." << endl;
    cout << "VAT: " << vat << " TL." << endl;
    cout << "Corporate Tax: 0 TL." << endl;
    cout << "" << endl;
    cout << "Capital Increase: 0 TL." << endl;
    cout << shareholders << " shareholders will have a share of: 0 TL." << endl;
    return 0;
    }
    if( profit > 0 && profit <= 10000)
    {
    corporatetax = (profit/10);
    netprofit = profit - corporatetax;
    capitalincrease = (netprofit/2);
    share = (capitalincrease * 0.85) / shareholders;
    cout << "Net Profit: " << netprofit << " TL." << endl;
    cout << "VAT: " << vat << " TL." << endl;
    cout << "Corporate Tax: " << corporatetax << " TL." << endl;
    cout << "" << endl;
    cout << "Capital Increase: " << capitalincrease << " TL." << endl;
    cout << shareholders << " shareholders will have a share of: " << share << " TL.";
    return 0;
    }
    if(10000 < profit && profit <= 25000)
    {
    corporatetax = profit * 0.15;
    netprofit = profit - corporatetax;
    capitalincrease = (netprofit/2);
    share = capitalincrease * 0.85 / shareholders;
    cout << "Net Profit: " << netprofit << " TL." << endl;
    cout << "VAT: " << vat << " TL." << endl;
    cout << "Corporate Tax: " << corporatetax << " TL." << endl;
    cout << "" << endl;
    cout << "Capital Increase: " << capitalincrease << " TL." << endl;
    cout << shareholders << " shareholders will have a share of: " << share << " TL.";
    return 0;
    }
    if(25000 < profit && profit <= 50000)
    {
    corporatetax = profit * 0.2;
    netprofit = profit - corporatetax;
    capitalincrease = (netprofit/2);
    share = (capitalincrease * 0.85) / shareholders;
    cout << "Net Profit: " << netprofit << " TL." << endl;
    cout << "VAT: " << vat << " TL." << endl;
    cout << "Corporate Tax: " << corporatetax << " TL." << endl;
    cout << "" << endl;
    cout << "Capital Increase: " << capitalincrease << " TL." << endl;
    cout << shareholders << " shareholders will have a share of: " << share << " TL.";
    return 0;
    }
    if (50000 < profit)
    {
    corporatetax = profit * 0.25;
    netprofit = profit - corporatetax;
    capitalincrease = (netprofit/2);
    share = (capitalincrease * 0.85) / shareholders;
    cout << "Net Profit: " << netprofit << " TL." << endl;
    cout << "VAT: " << vat << " TL." << endl;
    cout << "Corporate Tax: " << corporatetax << " TL." << endl;
    cout << "" << endl;
    cout << "Capital Increase: " << capitalincrease << " TL." << endl;
    cout << shareholders << " shareholders will have a share of: " << share << " TL.";
    return 0;
    }
                  
                
return 0;
}
    
            
        


