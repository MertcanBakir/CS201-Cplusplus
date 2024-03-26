//
//  main.cpp
//  CS201_HW2
//
//  Created by Mertcan Bakır on 28.10.2023.
//
#include <string>
#include <iostream>
using namespace std;
bool getCompanyData(string& companyName, string& location, double& grossIncome, double& expenses, double& numOfShareholders)
{
 cout << "Please enter the name of the company: " ;
 cin >> companyName;
 cout << "Is the company local or foreign? " ;
 cin >> location;
 if(location != "local" && location != "foreign")
 {
  cout << "Invalid location.";
  return false;
 }
 else
 {
    cout << "Please enter the gross income of " << companyName << ": " ;
    cin >> grossIncome;
    if(grossIncome < 1)
    {
     cout << "Invalid input for gross income.";
     return false;
    }
    else
    {
      cout << "Please enter expenses of " << companyName << ": " ;
      cin >> expenses;
      if(expenses < 0)
      {
       cout << "Invalid input for expenses.";
       return false;
      }
      else
      {
        cout << "Please enter the number of shareholders: ";
        cin >> numOfShareholders;
        if(numOfShareholders < 1)
        {
         cout << "Invalid input for the number of shareholders.";
         return false;
        }
        else
        {
          return true;
        }
      }
    }
 }
}





double calculateVAT(double grossIncome, string location)
{
    if(location == "local")
    {
        return  grossIncome * 0.15;
    }
    else{
        return grossIncome * 0.18;
    }
}
double calculateProfit(double grossIncome, double expenses, string location)
{
  if(location == "local")
  {
      return (grossIncome * 0.85) - expenses;
  }
  else
  {
      return (grossIncome * 0.82) - expenses;
  }
}
double calculateCorporateTax(double profit)
{
  if(profit > 0 && profit <= 10000)
  {
      return profit * 0.1;
  }
  else if(profit > 10000 && profit <= 25000)
  {
      return profit * 0.15;
  }
  else if(profit > 25000 && profit <= 50000)
  {
        return profit * 0.2;
  }
  else if(profit < 0)
  {
        return 0;
  }
  else
  {
      return profit * 0.25;
  }
}
double calculateNetProfit(double grossIncome, double expenses, string location)
{
 if(location == "local")
 {
     return ((grossIncome * 0.85) - expenses) - calculateCorporateTax(calculateProfit(grossIncome, expenses, location));
 }
 else
 {
    return ((grossIncome * 0.82) - expenses) - calculateCorporateTax(calculateProfit(grossIncome, expenses, location));
 }
}
double calculateDividend(double netProfit, int numOfShareholders)
{
    return (((netProfit / 2)* 0.85) / numOfShareholders);
}

void outputCompanyResults(string companyName, double grossIncome, double expenses, int numOfShareholders, string location)
{

    if(calculateNetProfit(grossIncome, expenses, location) < 0)
    {
      cout << "" << endl;
      cout << "*********** " << companyName << " Financial Report **********" << endl;
      cout << "" << endl;
      cout << "Net Loss: " << calculateNetProfit(grossIncome, expenses, location) << " TL." << endl;
      cout << "VAT: " << calculateVAT(grossIncome, location) << " TL." << endl;
      cout << "Corporate Tax: 0 TL." << endl;
      cout << "" << endl;
      cout << "Capital Increase: " << calculateNetProfit(grossIncome, expenses, location) / 2 << " TL." << endl;
      cout << numOfShareholders << " shareholders will have a share of: 0 TL." << endl;
      
     }
    else if(calculateNetProfit(grossIncome, expenses, location) > 0)
    {
        cout << "" << endl;
        cout << "*********** " << companyName << " Financial Report **********" << endl;
        cout << "" << endl;
        cout << "Net Profit: " << calculateNetProfit(grossIncome, expenses, location) << " TL." << endl;
        cout << "VAT: " << calculateVAT(grossIncome, location) << " TL." << endl;
        cout << "Corporate Tax: " << calculateCorporateTax(calculateProfit(grossIncome, expenses, location)) << " TL." << endl;
        cout << "" << endl;
        cout << "Capital Increase: " << calculateNetProfit(grossIncome, expenses, location) / 2 << " TL." << endl;
        cout << numOfShareholders << " shareholders will have a share of: " <<  calculateDividend(calculateNetProfit(grossIncome, expenses, location), numOfShareholders) <<" TL." << endl;
       
    }
    else
    {
        cout << "" << endl;
        cout << "*********** " << companyName << " Financial Report **********" << endl;
        cout << "" << endl;
        cout << "Net Profit: 0 TL. (Break Even)" << endl;
        cout << "VAT: " << calculateVAT(grossIncome, location) << " TL." << endl;
        cout << "Corporate Tax: 0 TL." << endl;
        cout << "" << endl;
        cout << "Capital Increase: 0 TL." << endl;
        cout << numOfShareholders << " shareholders will have a share of: 0 TL." << endl;
    }
}



int main()
{
    string companyName1, location1, companyName2, location2;
    double grossIncome1, expenses2,numOfShareholders1, grossIncome2, expenses1 ,numOfShareholders2;
    cout << "This accounting program calculates the state taxes and dividends for the company shareholders." << endl;
    if(getCompanyData(companyName1, location1, grossIncome1, expenses1, numOfShareholders1))
    {
        if(getCompanyData(companyName2, location2, grossIncome2, expenses2, numOfShareholders2))
        {
            
        
        /*
         cin >> grossIncome1 >> expenses1 >> location1 >> numOfShareholders1;
         cout << "VAT is: " << calculateVAT(grossIncome1, location1);
         cout << "Profit is: " << calculateProfit(grossIncome1, expenses1, location1);
         cout << "Corporate tax is: " << calculateCorporateTax(calculateProfit(grossIncome1, expenses1, location1));
         cout << "Net profit is: " << calculateNetProfit(grossIncome1, expenses1, location1);
         cout << "Share of the hissedarlar is: " << calculateDividend(calculateNetProfit(grossIncome1, expenses1, location1), numOfShareholders1);
         */
        outputCompanyResults(companyName1, grossIncome1, expenses1, numOfShareholders1, location1);
        outputCompanyResults(companyName2, grossIncome2, expenses2, numOfShareholders2, location2);
        if(calculateNetProfit(grossIncome1, expenses1, location1) > calculateNetProfit(grossIncome2, expenses2, location2))
        {
            cout << "" << endl;
            cout << companyName1 << " has a superior financial performance in terms of net profit compared to " << companyName2 << "." << endl;
        }
        else if(calculateNetProfit(grossIncome1, expenses1, location1) < calculateNetProfit(grossIncome2, expenses2, location2))
        {
            cout << "" << endl;
            cout << companyName2 << " has a superior financial performance in terms of net profit compared to " << companyName1 << "." << endl;
        }
        else
        {
            cout << "" << endl;
            cout << "Both " << companyName1 << " and " << companyName2 << " have an equivalent financial performance in terms of net profit." << endl;
      
       }
      }
    }
    return 0;
}
