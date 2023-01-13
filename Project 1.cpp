//Name: Cailyn Hyun
//Auburn ID: yzh0068
//Filename: Project1_Hyun_yzh0068
//compiler: Visual Studio Code 
//Source: Project1_hints.pdf(on Canvas) and lecture videos and "www.cplusplus.com"

#include<iostream>
using namespace std;

int main() {
//declare variables.
	int month = 0;
	double loanBalance;
	double interestRate;
	double monthlyPayment;
	double monthlyRate;
	double monthlyInterest;
	double loanBalanceDeduction;
	double finalTotalInterest = 0;

	//format to two decimal poitns
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	//loan amount input from user
	cout<<"Loan Amount: ";
	cin>>loanBalance;
	
	//warning
	if (!cin || loanBalance < 0) {
		cout<<"WARNING! Invalid loan amount"<<endl;
		return 0;
	}
	
	//interest rate input from user
	cout<<"Interest Rate (% per year): ";
	cin>>interestRate;
	
	//warning
	if (!cin || interestRate < 0){
		cout<<"WARNING! Invalid interest rate"<<endl;
		return 0;
	}
	
	//monthly payment input from user
	cout<<"Monthly Payment: ";
	cin>>monthlyPayment;
	
	//warning
	if (!cin || monthlyPayment < 0){
		cout<<"WARNING! Invalid payment"<<endl;
		return 0;
	}

	//calculate rate
	monthlyRate = (interestRate/12);
	monthlyInterest = ((loanBalance * monthlyRate)/100);
	loanBalanceDeduction = (monthlyPayment - monthlyInterest);
	finalTotalInterest = monthlyInterest;
	
	//warning
	if (monthlyInterest >= monthlyPayment){
		cout<<"WARNING! Insufficient payment"<<endl;
		return 0;
	}

	//graph starts here
	//line 74~78 is from www.cplusplus.com for formatting left aligned output
	cout<<endl;
	cout<<"***************************************************************************"<<endl;
	cout<<"\tAmortization Table"<<endl;
	cout<<"***************************************************************************"<<endl;
	std::cout.width(9); std::cout<<std::left<<"Month";
	std::cout.width(15); std::cout<<std::left<<"Balance";
	std::cout.width(15); std::cout<<std::left<<"Payment";
	std::cout.width(10); std::cout<<std::left<<"Rate";
	std::cout.width(15); std::cout<<std::left<<"Interest"<<"Principal"<<endl;

	//fill the first line of the table with N/A 
	//ine 82~86 is from www.cplusplus.com for formatting left aligned output
	std::cout.width(9); std::cout<<std::left<<month;
	cout<<"$"; std::cout.width(14); std::cout<<std::left<<loanBalance;
	std::cout.width(15); std::cout<<std::left<<"N/A";
	std::cout.width(10); std::cout<<std::left<<"N/A";
	std::cout.width(15); std::cout<<std::left<<"N/A"<<"N/A"<<endl;


	//fill in the table
	//line 95~99 is from www.cplusplus.com for formatting lift aligned output
	for (month = 1; loanBalance > monthlyPayment; month++) {
		loanBalance = (loanBalance - loanBalanceDeduction);	

		//left aligned output 
		std::cout.width(9); std::cout<<std::left<<month;
		cout<<"$"; std::cout.width(14); std::cout<<std::left<<loanBalance;
		cout<<"$"; std::cout.width(14); std::cout<<std::left<<monthlyPayment;
		cout<<"$"; std::cout.width(9); std::cout<<std::left<<monthlyRate;
		cout<<"$"; std::cout.width(14); std::cout<<std::left<<monthlyInterest;
		cout<<"$"<<loanBalanceDeduction<<endl;
		
		//calculate paid interest and balance deduction
		monthlyInterest = ((loanBalance * monthlyRate)/100);
		loanBalanceDeduction = (monthlyPayment - monthlyInterest);
		finalTotalInterest += monthlyInterest;
	}
	
	//last month 
	//line 110~114 is from www.cplusplus.com
	std::cout.width(9); std::cout<<std::left<<month; 
	cout<<"$"; std::cout.width(14); std::cout<<std::left<<"0.00";
	cout<<"$"; std::cout.width(14); std::cout<<std::left<<(monthlyInterest+loanBalance);
	cout<<"$"; std::cout.width(9); std::cout<<std::left<<monthlyRate;
	cout<<"$"; std::cout.width(14); std::cout<<std::left<<monthlyInterest;
	cout<<"$"<<loanBalance<<endl;
	cout<<"***************************************************************************"<<endl;
	
	//final conclusion
	cout<<"\nIt takes "<<month<<" month(s) to pay off the loan.";
	cout<<"\nTotal Interest paid is : $"<<finalTotalInterest<<endl;
	cout<<endl;
		
	return 0;
	
}


 	
