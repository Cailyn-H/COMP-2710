//Cailyn Hyun, yzh0068, project2_Hyun_yzh0068
//sources: watching courses video and Canvas project2 hints.pdf
//compiler : Visual studio Code.
//compile command: g++ Project2_Hyun_yzh0068 and then ./a.out
//press enter twice when "Press any key to continue..." comes up


# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>

using namespace std;

//declaring int and String Boxes.( variable )
const int aaronInformation = 33;
const int bobInformation = 50;
const int TOTALAPPRUNNING = 10000;
const string PRINTDIVIDE = "/10000";

int FirstWinCount1;
int FirstWinCount2;
int SecWinCount1;
int SecWinCount2;
int ThWinCount1;
int ThWinCount2;
int num1;
int num2;

bool A_Alive;
bool B_Alive;
bool C_Alive;
bool True = true;
bool False = false;

string target;


/* at_least_two_alive() function prototype */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
    //input and Return will be here.

/* Aaron_shoots1() function prototype */
void Aaron_shoots1(bool& B_alive, bool& C_alive);
  //input and Return will be here.
    
/* Bob_shoots() function prototype */
void Bob_shoots(bool& A_alive, bool& C_alive);
   //input and Return will be here.

/* Charlie_shoots() function prototype */   
void Charlie_shoots(bool& A_alive, bool& B_alive);
  //input and Return will be here.
/* Aaron_shoots2() function prototype */    
void Aaron_shoots2(bool& B_alive, bool& C_alive);
   //input and Return will be here.

// TEST METHOD PROTOTYPES
void test_at_least_two_alive(void);
/* This is a test driver for at_least_two_alive() */
//test driver
void test_Aaron_shoots1(void);
/* This is a test driver for Aaron_shoots() */
//test driver
void test_Bob_shoots(void);
/* This is a test driver for Bob_shoots() */
//test driver
void test_Charlie_shoots(void);
/* This is a test driver for Charlie_shoots() */
//test driver
void test_Aaron_shoots2(void);
/* This is a test driver for Aaron_shoots2() */
//test driver
/* Function for the continue key */
void continueKey() {
   cout << "Press any key to continue...";
   //press any key in here.
   cin.ignore().get(); //Pause Command for Linux Terminal
   cout << endl;
}

/* Strategy 1 Driver */
void strategy1Driver() {
   cout << endl;
   cout << "Ready to test strategy 1 (run " << TOTALAPPRUNNING << " times):" << endl;
   continueKey();
   cout << endl;
//explain this. first, this sentense need to correct in for sentense.
/* and start do sentense, do need to start least one.
and then in while sentense judge true or false.
and this will be in start if sentense and add + 1.*/

//do while statement.
   for (int i = 0; i < TOTALAPPRUNNING; i++) {
      A_Alive = B_Alive = C_Alive = true;
      do {
         if (A_Alive) {
            Aaron_shoots1(B_Alive, C_Alive);
         }
         if (B_Alive) {
            Bob_shoots(A_Alive, C_Alive);
         }
         if (C_Alive) {
            Charlie_shoots(A_Alive, B_Alive);
         }
      } while (at_least_two_alive(A_Alive, B_Alive, C_Alive));
      if (A_Alive) {
         FirstWinCount1 = FirstWinCount1 + 1;
      }
      if (B_Alive) {
         SecWinCount1 = SecWinCount1 + 1;
      }
      if (C_Alive) {
         ThWinCount1 = ThWinCount1 + 1;
      }
   }
   double percent1 = FirstWinCount1 * 0.01;
   double percent2 = SecWinCount1 * 0.01;
   double percent3 = ThWinCount1 * 0.01;
   cout << "Aaron won " << FirstWinCount1 << PRINTDIVIDE << " duels or " << percent1 << "%" <<endl;
   cout << "Bob won " << SecWinCount1 << PRINTDIVIDE << " duels or " << percent2 << "%" << endl;
   cout << "Charlie won " << ThWinCount1 << PRINTDIVIDE << " duels or " << percent3 << "%";
}

/* Strategy 2 Driver */
void strategy2Driver() {
   cout << endl;
   cout << endl;
   cout << "Ready to test strategy 2 (run " << TOTALAPPRUNNING << " times):" << endl;
   continueKey();
   cout << endl;
 //explain this. first, this sentense need to correct in for sentense.
/* and start do sentense, do need to start least one.
and then in while sentense judge true or false.
and this will be in start if sentense and add + 1.*/
   for (int i = 0; i < TOTALAPPRUNNING; i++) {
      A_Alive = B_Alive = C_Alive = true;
      do {
         if (A_Alive) {
            Aaron_shoots2(B_Alive, C_Alive);
         }
         if (B_Alive) {
            Bob_shoots(A_Alive, C_Alive);
         }
         if (C_Alive) {
            Charlie_shoots(A_Alive, B_Alive);
         }
      } while (at_least_two_alive(A_Alive, B_Alive, C_Alive));
      if (A_Alive) {
         FirstWinCount2 =FirstWinCount2 + 1;
      }
      if (B_Alive) {
         SecWinCount2 =SecWinCount2 + 1;
      }
      if (C_Alive) {
         ThWinCount2 =ThWinCount2 + 1;
      }
   }
   //getting percent1 , 2 and 3.
   double percent1 = FirstWinCount2 * 0.01;
   double percent2 = SecWinCount2 * 0.01;
   double percent3 = ThWinCount2 * 0.01;
   cout << "Aaron won " << FirstWinCount2 << PRINTDIVIDE << " duels or " << percent1 << "%"<<endl;
   cout << "Bob won " << SecWinCount2 << PRINTDIVIDE << " duels or " << percent2 << "%"<<endl;
   cout << "Charlie won " << ThWinCount2 << PRINTDIVIDE << " duels or " << percent3 << "%";
//if statement.
   if (FirstWinCount2 > FirstWinCount1) {
      num2 = 2;
      num1 = 1;
   }
   //after if statement, and will start else if . and then else sentence.
   else if (FirstWinCount2 == FirstWinCount1) {
      cout << endl;
      cout << endl;
      cout << "Strategy 2 is equal to strategy 1." << endl;
      return;
   }
   else {
      num2 = 1;
      num1 = 2;
   }
   cout << endl;
   cout << endl;
   cout << "Strategy " << num2 << " is better than strategy " << num1 << "." << endl;
}

// main method is start method.
int main() {
   srand(time(0));
   cout << "*** Welcome to Cailyn's Duel Simulator ***" << endl;
   //under is getting all each under method.
   test_at_least_two_alive();
   test_Aaron_shoots1();
   test_Bob_shoots();
   test_Charlie_shoots();
   test_Aaron_shoots2();
   strategy1Driver();
   strategy2Driver();
}

// function definition.
/* Implementation of at_least_two_alive() */
//bool is judge true or false.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   int count = 0;

   if (A_alive) {
      count++;
   }
   if (B_alive) {
      count++;
   }
   if (C_alive) {
      count++;
   }

   if (count > 1) {
      return true;
   }
   else {
      return false;
   }
}

/* Implementation of Aaron_shoots1() */
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   B_Alive = B_alive;
   C_Alive = C_alive;
   int randomNumber = rand()%100;

   if (C_Alive) {
      target = "Charlie";
   }
   else {
      target = "Bob";
   }

   if (randomNumber <= aaronInformation) {
      if (target == "Charlie") {
         C_Alive = false;
         return;
      }
      else {
         B_Alive = false;
         return;
      }
   }
   else {
      return;
   }
}

/* Implementation of Bob_shoots() */
void Bob_shoots(bool& A_alive, bool& C_alive) {
   A_Alive = A_alive;
   C_Alive = C_alive;
   int randomNumber = rand()%100;

   if (C_Alive) {
      target = "Charlie";
   }
   else {
      target = "Aaron";
   }

   if (randomNumber <= bobInformation) {
      if (target == "Charlie") {
         C_Alive = false;
      }
      else {
         A_Alive = false;
      }
   }

}

/* Implementation of Charlie_shoots() */
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   A_Alive = A_alive;
   B_Alive = B_alive;
//if B_Alive start this.
   if (B_Alive) {
      B_Alive = false;
      target = "Bob";
   }
   //else is if (if is false) start this.
   else {
      A_Alive = false;
      target = "Aaron";
   }
}

/* Implementation of Aaron_shoots2() */
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   B_Alive = B_alive;
   C_Alive = C_alive;
   int randomNumber = rand()%100;
   
   if ((B_Alive == true) && (C_Alive == true)) {
      return;
   }

   if (C_Alive) {
      target = "Charlie";
   }
   else {
      target = "Bob";
   }

   if (randomNumber <= aaronInformation) {
      if (target == "Charlie") {
         C_Alive = false;
         return;
      }
      else {
         B_Alive = false;
         return;
      }
   }
   else {
      return;
   }
}

// test function
/* Implementation of the test driver for at_least_two_alive() */
// case is start after main method.
//case 1,2,3,4,5,6,7 and 8.
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()"<<endl;
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive"<<endl;
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ..."<<endl;
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive"<<endl;
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ..."<<endl;
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive"<<endl;
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ..."<<endl;
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead"<<endl;
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ..."<<endl;
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive"<<endl;
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ..."<<endl;
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead"<<endl;
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ..."<<endl;
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead"<<endl;
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ..."<<endl;
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead"<<endl;
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ..."<<endl;
   continueKey();
}

/* Implementation of the test driver for Aaron_shoots1() */
void test_Aaron_shoots1(void) {
//case1, 2 and 3. test about aaron shoot1
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)"<<endl;
   cout << "\t\tCase 1: Bob alive, Charlie alive"<<endl;
   cout << "\t\t\tAaron is shooting at Charlie" << endl;
   Aaron_shoots1(True, True);
   cout << "\t\tCase 2: Bob dead, Charlie alive"<<endl;
   cout << "\t\t\tAaron is shooting at Charlie" <<endl;
   Aaron_shoots1(False, True);
   cout << "\t\tCase 3: Bob alive, Charlie dead"<<endl;
   cout << "\t\t\tAaron is shooting at Bob" <<endl;
   Aaron_shoots1(True, False);
   continueKey();
}

/* Implementation of the test driver for Bob_shoots() */
void test_Bob_shoots(void) {
//case 1, 2 and 3. test bob shoots.
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)"<<endl;
   cout << "\t\tCase 1: Aaron alive, Charlie alive"<<endl;
   cout << "\t\t\tBob is shooting at Charlie"<<endl;
   Bob_shoots(True, True);
   cout << "\t\tCase 2: Aaron dead, Charlie alive"<<endl;
   cout << "\t\t\tBob is shooting at Charlie"<<endl;
   Bob_shoots(False, True);
   cout << "\t\tCase 3: Aaron alive, Charlie dead"<<endl;
   cout << "\t\t\tBob is shooting at Aaron" <<endl;
   Bob_shoots(True, False);
   continueKey();
}

/* Implementation of the test driver for Charlie_shoots() */
void test_Charlie_shoots(void) {
//case1, 2 and 3. test charlie shoots.
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)"<<endl;
   cout << "\t\tCase 1: Aaron alive, Bob alive"<<endl;
   cout << "\t\t\tCharlie is shooting at Bob" <<endl;
   Charlie_shoots(True, True);
   cout << "\t\tCase 2: Aaron dead, Bob alive"<<endl;
   cout << "\t\t\tCharlie is shooting at Bob" <<endl;
   Charlie_shoots(False, True);
   cout << "\t\tCase 3: Aaron alive, Bob dead"<<endl;
   cout << "\t\t\tCharlie is shooting at Aaron" <<endl;
   Charlie_shoots(True, False);
   continueKey();
}

/* Implementation of the test driver for Aaron_shoots2() */
void test_Aaron_shoots2(void) {
//case1, 2 and 3. test Aaron shoots2.
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)"<<endl;
   cout << "\t\tCase 1: Bob alive, Charlie alive"<<endl;
   cout << "\t\t\tAaron intentionally misses his first shot\n\t\t\tBoth Bob and Charlie are alive."<<endl;
   Aaron_shoots2(True, True);
   cout << "\t\tCase 2: Bob dead, Charlie alive"<<endl;
   cout << "\t\t\tAaron is shooting at Charlie"<<endl;
   Aaron_shoots2(False, True);
   cout << "\t\tCase 3: Bob alive, Charlie dead"<<endl;
   cout << "\t\t\tAaron is shooting at Bob" << endl;
   Aaron_shoots2(True, False);
   continueKey();
}