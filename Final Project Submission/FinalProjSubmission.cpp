// Program Name: Term Project - Financial Calculator
// Purpose: Write a program that lets the user calculate student loan debt, three different types of depreciation, and mortgage payment amount.
// Author: [Erin O'Connor]
// Date Last Modified: [April 20 2019]

//This program is a calculator that gives the user three options: a student loan calculator, asset depreciation calculator, and mortgage calculator.
//Within these three options, the user has a choice. They can choose to calculate their monthly payment amount for their student loan,
//They can choose to calculate depreciation expense with three different depreciation methods (Straight line, double declining balance, and sum of the years digits),
//Or, they can choose to calculate their monthly payment amount for the mortgage for their home.


#include <iostream>
#define _USE_MATH_DEFINES //for math functions
#include <cmath> //for math functions
#include <iomanip> //for decimal formatting
using namespace std;

int firstMenu(); //Basic Menu with four main calculator options
  void studentLoanCalculator(); //for Student Loan Calculator
  int depreciationMenu(); //for menu within Depreciation Calculator
  void mortgageCalculator(); //for mortgage Calculator

//Student Loan function
double monthlyPayment(); //for montly payment option

//Depreciation functions
void straightLine(); //for Straight Line Depreciation
void decliningbalance(); // for Double Declining Balance Depreciation
void sumofyears(); //for Sum of Years Digits Depreciation

int main ()
{

  int firstMenuChoice, secondMenuChoice; //for first Menu choice and Second Menu choice (within depreciation menu)
  do
  {
    firstMenuChoice = firstMenu();

    if (firstMenuChoice == 1)
      studentLoanCalculator(); //call student loan menu function

    else if (firstMenuChoice == 2)
    {
      secondMenuChoice = depreciationMenu(); //call depreciation menu function
      if (secondMenuChoice == 1)
        straightLine(); //straight line depreciation function
      else if (secondMenuChoice == 2)
        decliningbalance(); //declining balance depreciation function
      else if (secondMenuChoice == 3)
        sumofyears(); //sum of the years digits depreciation function
    }

    else if (firstMenuChoice == 3)
      mortgageCalculator(); //call mortgage function

    //if user enters a number greater than 4 or less than 1 - outputs invalid input message
    else if (firstMenuChoice > 4 || firstMenuChoice < 1)
    {
      cout << "Invalid input - sorry! Please try again, but this time, with a number from 1-4. " << endl; //Invalid input message

    }

    // user quit option if user enters 4
  }
  while (firstMenuChoice !=4);

  cout << "Thank you for using this program! See you next time!";
  return 0;
}

//For first menu choice
int firstMenu() {
  int firstMenuChoice; //declaring variables

  cout << "Hello! Welcome to the Advanced Financial Calculator. You have four options:" << endl; //Welcome message
  cout << "1. Student Loan Calculator" << endl; // Student Loan Calculator
  cout << "2. Depreciation Calculator" << endl; // Asset Depreciation Calculator
  cout << "3. Mortgage Calculator" << endl; //House Mortgage Calculator
  cout << "4. Quit" << endl; // Quit Option
  cout << "Enter a number (1-4): "; // Prompts user to enter a number 1-4
  cin >> firstMenuChoice; // Get user choice

  return firstMenuChoice; //returns first menu choice
}

// Student Loan Calculator Menu
void studentLoanCalculator()
{
  double loanAmount, interestRate, numberofPayments, monthlyInterest, monthlyPayment; //variables for Loan Amount, Interest Rate, Number of monthly payments, Monthly Interest, and Monthly Payment Amount

  cout << "Welcome to the Student Loan Calculator! Student loan debt can be a pain, but I can save you\ntime when it comes to calculating it." << endl; //Welcome message for Student Loan calculator Menu
  cout << "If you enter some information for me, I can calculate your monthly payment amount for your loan." << endl;
  cout << "First, enter the total loan amount: " << endl; //Prompts user to enter the total loan amount
  cin >> loanAmount; //Retrieves total student loan amount
  cout << "Enter the interest rate (yearly): " << endl; //Prompts user to enter the yearly interest rate for loan
  cin >> interestRate; //Retrieves interest rate for loan
  cout << "Enter the number of payments to be made: " << endl; //Prompts user to enter the total number of payments to be made on student loan
  cin >> numberofPayments; //Retrieves total number of payments

  cout << endl << "GETTING LOAN INFORMATION ..." << endl; //output for Loan Information Header
  cout << "Loan amount: $" << loanAmount << endl; //output for user-provided Loan Amount
  cout << "Interest Rate: " << interestRate << "%" << endl; //output for user-provided Interest Rate
  cout << "Number of payments: " << numberofPayments << endl; //output for user-provided payment number

  //Formula for Monthly Interest Calculation
  monthlyInterest = pow ( (1.0 + interestRate) , (1.0/numberofPayments) ) - 1.0;

  //Monthly interest output (in percent)
  cout << "Monthly Interest: " << monthlyInterest * 100 << "%" << endl << endl;

  //Formula for Monthly payment calculation
  monthlyPayment = monthlyInterest * pow ((1 + monthlyInterest ), numberofPayments) / (pow(( 1 + monthlyInterest), numberofPayments) -1) * loanAmount;

  //Monthly Payment output
  cout << "CALCULATING MONTHLY PAYMENT ..." << endl;

  //to ensure decimal points do not go past 2 and monthly payment output. Additionally, goodbye message
  cout << fixed << setprecision(2) << "Based on the information given, your monthly payment amount is: $"  << monthlyPayment << ". Have a good day!" << endl << endl;
}

// Depreciation Calculator Menu
int depreciationMenu()
{
  int depreciationChoice; //Declaring variables for user depreciation choice

  cout << "Welcome to the Depreciation Calculator! As a business owner, it is important to calculate depreciation expense." << endl; //Welcome Message
  cout << "For your asset, the type of depreciation your business uses can impact your overall net income and depreciation amount." << endl; //Welcome Message
  cout << "With that being said, I can calculate three different types of depreciation for you:" << endl << endl; //Gives user three options for depreciation calculation
  cout << "1) Straight Line Depreciation" << endl; //Straight Line Depreciation option
  cout << "2) Double Declining Balance Depreciation" << endl; //Double Declining Balance Depreciation option
  cout << "3) Sum of the Years Digits Depreciation" << endl; //Sum of the Years Digits Depreciation option
  cout << "Enter the number that corresponds with the depreciation type you'd like me to calculate: "; //Prompt user to enter the number for which option they would like
  cin >> depreciationChoice; //Get user choice for Depreciation option
  return depreciationChoice; //returns depreciation choice
}

      //for Straight Line Depreciation
      void straightLine()
      {
        double slDepreciationExp, assetCost, residualValue, usefulLife; //declaring variables for Straight Line Depreciation Expense, Asset cost, Residual value, and Useful life of asset

        cout << "I see you've decided to use straight line as your method of depreciation calculation! \n While it has some drawbacks, it is the simplest form." << endl << endl; //Introduction message
        cout << "To calculate it, I will need some information first:" << endl;
        cout << "Enter the asset's cost: "; //Prompts user for asset cost
        cin >> assetCost; //Retrieves asset cost
        cout << "Enter the asset's residual/salvage value: "; //Prompts user for asset residual/salvage value
        cin >> residualValue; //Retrieves asset residual value
        cout << "Enter the asset's useful life: "; //Prompts user for asset's useful life
        cin >> usefulLife; //Retrieves asset useful life

        // Asset information output
        cout << "ASSET INFORMATION ..." << endl; //asset information header
        cout << "Asset Cost: $" << assetCost << endl; //asset cost (in USD) output
        cout << "Asset Residual Value: $" << residualValue << endl; //asset residual value (in USD) output
        cout << "Asset Useful Life: " << usefulLife << " years" << endl; //asset useful life in years

        //Formula for Calculation for straight line depreciation expense = Residual Value subtracted from Asset Cost all divided by Asset Useful Life
        slDepreciationExp = (assetCost - residualValue) / (usefulLife);

        //Output for depreciation expense
        cout << "CALCULATING DEPRECIATION EXPENSE ..." << endl; //Depreciation Expense header output
        cout << "Based on my calculations, the yearly depreciation expense for your asset will be $" << slDepreciationExp << ". Have a good day!" << endl << endl; //S/L Depreciation Expense output and goodbye message
      }

      //Double Declining Balance
      void decliningbalance ()
      {
        double doubledecliningbalExp, assetCost, accumulatedDepreciation, yearNumber, bookValue, usefulLife; //declaring variables for Double Declining Balance Expense, Asset Cost, Accumulated Depreciation of Asset, Depreciation Year Number, Asset Book Value, and Asset Useful Life

        cout << "\nThis method of depreciation causes the asset to be depreciated much faster than with other methods.\nOnly choose this method if your asset will lose value early in its useful life." << endl; //Introductory message about Double Declining Balance
        cout << "Another tricky thing about double declining balance: the depreciation expense differs by year. \n \nSo, for what year in your asset's useful life do you want me to calculate depreciation expense?" << endl; //Asks user for what year do they want program to calculate depreciation expense
        cin >> yearNumber; //Retrieves depreciation year number from user
        cout << "I can work with that! However, I'll need some more information." << endl;
        cout << "Enter the asset's cost: " << endl; //Prompts user for asset cost
        cin >> assetCost; //Retrieves asset cost
        cout << "Enter the asset's accumulated depreciation amount (if none yet, enter 0): " << endl; //prompts user for asset's accumulated depreciation amount
        cin >> accumulatedDepreciation; //Retrieves accumulated depreciation amount
        cout << "Enter the asset's useful life: "; //Prompts user to enter asset's useful life
        cin >> usefulLife; //Retrieves useful life of asset


        //Formulas for calculating book value and double declining balance depreciation expense
        bookValue = (assetCost - accumulatedDepreciation); // need to calculate book value in order to calculate declining balance expense
        doubledecliningbalExp = (bookValue) * (2 / usefulLife); //depreciation expense

        // Asset information output
        cout << "ASSET INFORMATION ..." << endl; //Asset information header
        cout << "Asset Cost: $" << assetCost << endl; //Asset cost in USD output
        cout << "Asset Accumulated Depreciation: " << accumulatedDepreciation << endl; //Asset Accumulated Depreciation in USD output
        cout << "Asset Useful Life: " << usefulLife << " years" << endl; //Asset Useful life in years output
        cout << "Asset Book Value: $" << bookValue << endl; //Asset book value in USD output


        // Output for depreciation expense
        cout << "CALCULATING DEPRECIATION EXPENSE ..." << endl; //Depreciation Expense header output
        cout << "Based on my calculations, the asset depreciation expense for year " << yearNumber << " is $" << doubledecliningbalExp << ". Have a good day!" << endl << endl; //Depreciation Expense output and goodbye message
      }

      //Sum of Years Digits Depreciation
      void sumofyears()
      {
        int assetCost, usefulLife, assetYear, sumofyearsDigits, soydExpense; //declaring variables for Asset cost, Asset year for depreciation calculation, Sum of the Years Digits, and Sum of the Years Digits Depreciation Expense
        cout << "The sum of the years digits method is a form of accelerated depreciation." << endl; //Introductory Message about Sum of the Years Digits Depreciation
        cout << "Only use this method if the productivity of your asset decreases with the passage of time!" << endl; //Introductory Message about Sum of the Years Digits Depreciation
        cout << "To calculate depreciation expense, I will need some information first:" << endl;
        cout << "Enter the asset cost: " << endl; //Prompts user to enter asset cost in USD
        cin >> assetCost; //Retrieves asset cost
        cout << "Enter the remaining useful life of the asset: "; //Prompts user to enter remaining useful life of asset
        cin >> usefulLife; //Retrieves asset's remaining useful life
        cout << "Enter the year that you want me to calculate depreciation expense for: " << endl; //Prompts user to enter year for depreciation expense calculation
        cin >> assetYear; //Retrieves year for depreciation expense calculation

        //Sum of the Years Digits formula: Need to calculate sum of years digits before calculating depreciation expense
        sumofyearsDigits = ((usefulLife + 1 / 2) * usefulLife);

        // Asset information output
        cout << "ASSET INFORMATION ..." << endl; //Asset information header output
        cout << "Asset Cost: $" << assetCost << endl; //Asset cost in USD output
        cout << "Remaining Useful Life of Asset: " << usefulLife << " years" << endl; //Remaining useful life of asset in years output
        cout << "Sum of Years Digits for Asset: " << sumofyearsDigits << endl; //Sum of the Years Digits for asset output

        //Formula for Sum of the Years Digits (soydExpense) Depreciation expense calculation
        soydExpense = ((usefulLife / sumofyearsDigits) * assetCost);

        //Depreciation expense output
        cout << "CALCULATING DEPRECIATION EXPENSE ..." << endl; //Calculating depreciation expense output
        cout << "Based on my calculations, the depreciation expense for your asset is $" << soydExpense << ". Have a good day!" << endl << endl; //SOYD Depreciation Expense output and goodbye message
        }


// Mortgage Calculator
void mortgageCalculator()
{
  double loanAmount, interestRate, loanYears, monthlyinterestRate, mortMonthlyPay, totalMortgageCost; //declaring variables for mortgage loan amount, interest rate of loan, amount of years for loan, monthly interest rate for loan, mortgage monthly payment amount, and total mortgage cost
  int totalPayments; //declaring variables
  cout << "Welcome to the Mortgage Calculator! Congratulations, homeowner! What a big step in your life!" << endl; //Welcome message
  cout << "If provided with the amount of your mortgage loan, interest rate, and loan period, I can calculate your monthly payment amount." << endl;
  cout << "First, enter the total amount of your loan: " << endl; //Prompts user to enter total amount of mortgage loan
  cin >> loanAmount; //Retrieves mortgage loan amount
  cout << "Enter the interest rate: " << endl; //Prompts user to enter interest rate for loan
  cin >> interestRate; //Retrieves interest rate for loan
  cout << "Enter the period of your loan (in years): " << endl; //Prompts user to enter period of mortgage loan in years
  cin >> loanYears; //Retrieves period of mortgage loan

  //Calculations for monthly payment amount
  monthlyinterestRate = interestRate / 1200; //calculating interest rate for compounding monthly
  totalPayments = loanYears * 12; //Calculation for total number of payments by multiplying the number of years for loan by 12 months in a year
  mortMonthlyPay = (loanAmount * monthlyinterestRate) / (1.0 - pow (monthlyinterestRate + 1, -totalPayments)); //formula for calculating monthly payment amount for mortgage
  totalMortgageCost = (mortMonthlyPay * totalPayments); //formula for calculating total mortgage cost by multiplying mortgage monthly payment amount by total payments

  //Mortgage information Output
  cout << "GATHERING MORTGAGE LOAN INFORMATION ..." << endl; //Mortgage loan information header
  cout << "Mortgage Amount: $" << loanAmount << endl; //Mortgage amount in USD output output
  cout << "Loan Interest Rate: " << interestRate << "%" << endl; //Loan interest rate in percentage output
  cout << "Period of Mortgage: " << loanYears << " years" << endl; //Mortgage loan period in years output
  cout << "Total Monthly Payments: " << totalPayments << endl; //Total monthly payments output


  //To ensure decimal places do not pass 2 and monthly payment amount output
  cout << fixed << setprecision(2) << "Based on the information given, your monthly payment amount for your loan is: $" << mortMonthlyPay << "." << endl;
//To ensure decimal places do not pass 2 and Total mortgage cost output
  cout << fixed << setprecision(2) << "Additionally, the total mortgage cost is " << totalMortgageCost << ". Not too shabby! Have a good day!" << endl << endl;
}
