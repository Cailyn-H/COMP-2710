/*
* i watched comp2710 lecture video and referenced project4 hint
*Cailyn Hyun
*903883953
*yzh0068@auburn.edu
*g++ Project4_Hyun_yzh0068.cpp
*./a.out
* 
*/


# include <iostream>
# include <cstring>
# include <assert.h>
# include <cstdlib>

using namespace std;


/**
 * creates a trivia node structure containing information about a single trivia question
 * and a pointer pointing to the other TriviaNode.
 **/
 
 //question and answer and point and triviaNode *next.
struct triviaNode {
   string questionIt;
   string answer;
   int points;
   triviaNode *next;
};



//triviaList
class triviaList
  {
     public:
   int countNumber;
   triviaNode *head, *root;
   //triviaList() { number = 0; head = no (Null) root = no (Null)}.
   triviaList()
   {
      countNumber = 0;
      head = NULL;
      root = NULL;
   }
  };
  
  	

/**
 * initializes the Trivia questions
 * this si initializeList get &tL.
 **/
void initializeList(triviaList &tL) {
//*question1, *question2, *question3.
   triviaNode *question1 = new triviaNode;
   triviaNode *question2 = new triviaNode;
   triviaNode *question3 = new triviaNode;


//This is Trivia Question 1
   question1 -> questionIt = "How long was the shortest war on record? (Hint: how many minutes)";
   question1 -> answer = "38";
   question1 -> points = 100;
   question1 -> next = question2;


//THis is Trivia Question 2
   question2 -> questionIt = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   question2 -> answer = "Bank of Italy";
   question2 -> points = 50;
   question2 -> next = question3;


//THis is Trivia Question 3
   question3 -> questionIt = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
   question3 -> answer = "Wii Sports";
   question3 -> points = 20;
   question3 -> next = NULL;  
   
      
//head of tL, root of tL and Count of tL.
   tL.head = question1;
   tL.root = question3;
   tL.countNumber += 3;
}

/**
 * this function asks the player a question 
 * */
 
 
int askQuestion(triviaList tL, int i, int &bonusPoint) {
    //triviaNode *q = tL.head;
   
 //parameter checking 
 //divide using if statment.
   if (i < 1) { // checks if the number of trivia questions is equal to zero
      cout << "Warning - The number of trivia to be asked must equal to or be larger than 1.";
      return 1;
   }
   if (i > tL.countNumber) { //checks if the number of trivia questions exceeds the number of questions in the list
      cout << "\nWarning - There are only " << tL.countNumber << " trivia in the list";
      i = tL.countNumber;
      return 0;
   }
   triviaNode *q = tL.head;
   
   string ans;
   bonusPoint = 0;
   //using for statement p = 0 to p < i
   for (int p = 0; p < i; p++) {
      cout << "\nQuestion: " << q -> questionIt << "\nAnswer: ";
      getline(cin, ans);
      //correct answer.
      if (q -> answer == ans) {
         cout << "Your answer is correct. You receive " << q -> points << " points.";
         bonusPoint += q -> points; //adds points to total point value   
      }   
      //if not correct. 
      else {
         cout << "Your answer is wrong. The correct answer is: " << q -> answer;
      }
      cout << "\nYour Total Points: " << bonusPoint << endl; 
      q = q -> next;
   }
   return 0; 
}

void addTrivia(triviaList &tL){
   string responseThis;
   do {
      tL.countNumber++; //increases the countNumber of questions
      triviaNode *temp = new triviaNode;
    //the user to enter a question
      cout << "Enter a question: ";
      getline(cin, temp -> questionIt);
    //the user to create an answer to their question
      cout << "Enter an answer: ";
      getline(cin, temp -> answer);
    //the user creates a point value to be awarded to the player
      cout << "Enter award points: ";
      cin >> temp -> points;
   //the user to continue
      cout << "Continue? (Yes/No): ";
      getline(cin.ignore(), responseThis);
    
    //adds new trivia to list
      tL.root -> next = temp;
      tL.root = temp;
        
   }
   while (responseThis.find("Yes") != string :: npos);
}


void test_askQuestion()
{
	// Initialize test fixtures
   triviaList tL;
   int bonusPoint;
	
	// Setup Trivia list
   initializeList(tL);

   
	//start  Case 1
   cout << "Unit Test Case 1: Ask no questions. The program should give a warning message.\n";
	
    // Run assertions 
   assert(1 == askQuestion(tL, 0, bonusPoint));
   cout << "\nCase 1 passed\n";
	
	//start Case 2.1
   cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters the incorrect answer.\n";

	//start Run assertions
   assert(0 == askQuestion(tL, 1, bonusPoint));
   //assert(0 == bonusPoint);
   cout << "\nCase 2.1 passed\n";

	//start Case 2.2
   cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters an correct answer.\n";
	
	//start assertions
   assert(0 == askQuestion(tL, 1, bonusPoint));
   //assert(100 == bonusPoint);
   cout << "\nCase 2.2 passed\n";

	// start Case 3.1
   cout << "\nUnit Test Case 3: Ask all of the questions in the linked list. The tester enters the correct answers.\n";

	// start assertions
   assert(0 == askQuestion(tL, 3, bonusPoint));
	// score.
   //assert(170 == bonusPoint);
   cout << "Case 3 passed\n";

	// start Case 4
   cout << "\nUnit Test Case 4: Attempt to ask 5 questions in the linked list. Program should give a warning message.\n";
   assert(0 == askQuestion(tL, 5, bonusPoint));
   cout << "\nCase 4 passed\n";
}



// main function main().

/*
*  start ifedf UNIT_TESTING
*/
#define trivia_quiz

int main() {
    //if setting in here about else starting debug.
   cout << "*** This is a debugging version ***\n";
   test_askQuestion();
   cout << "\n*** End of the debugging version ***\n";
   //if setting in here about else starting this game.

 //insert production code   
//start trivia game.
#ifdef trivia_quiz
   cout << "*** Welcome to Cailyn's trivia quiz ***" << endl;
   triviaList gametrivia;
   int bonusPoint;
   initializeList(gametrivia);
   addTrivia(gametrivia);
    
   cout << "\n" << endl;
    
   askQuestion(gametrivia, gametrivia.countNumber, bonusPoint);
    

   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
    
    
    //finish it.
   return 0;
}
#endif

#ifdef UNIT_TESTING
{
	test_askQuestion();
    return 0;
}   
#endif