/*
Cailyn Hyun
yzh0068
Project3_Hyun_yzh0068.cpp
source: I watched lecture videos and followed design issues on project3 instruction. 
outsource: I also watched youtube on how to convert string to int not using stoi link is https://youtu.be/vR1fI7vkFsQ
outsource2: the program worked on vscode but not on AU server. It turns out that compiler version did not match so I had to
            add .c_str() when opening the file. I got this information on stackoverflow link is https://stackoverflow.com/questions/28521561/why-this-compiler-error-no-matching-function-for-call-to-stdbasic-ofstream
compiler: visual studio code
compile command: g++ Project3_Hyun_yzh0068.cpp and then ./a.out
WARNING: if there is a empty line (with enter) after the integer in input text file, the last integer gets executed twice. 
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//readfile using *inputArray and fstream & intstream
int readfile(int *inputArray, fstream &intstream) {
//variable
   string s;
   int numberrr;
   int a;
   //for statement 
   for (numberrr = 0; getline(intstream, s); numberrr++){
       //stoi did not work so I am using istringstream
       //also include sstream
       //I learned this in youtube https://youtu.be/vR1fI7vkFsQ
       istringstream(s) >> a;
        inputArray[numberrr] = a;
   } 
   //return it in the numberrr.
   return numberrr;
}



//sort using array tech.
int sort(int *inputArray, int inputArray_size) {
   for (int i = 0; i < inputArray_size; i++){
   //for in for if i = 0 this going to all j etc...
      for (int j = i+1; j < inputArray_size; j++) {
         if (inputArray[i] > inputArray[j]){
            int tmppend = inputArray[i];
            inputArray[i] = inputArray[j];
            inputArray[j] = tmppend;
         } 
      }
   }
   //return this inputArrat_size.
   return inputArray_size;
}




//this si wiretfile about outputarraay etc...
void writefile(int *outputarray, int outputArray_size, ofstream &sout) {
   cout << "\nThe sorted list of " << outputArray_size << " numbers is: ";
   for (int i = 0; i < outputArray_size; i++) {
   //beteween sorted list space area.
      sout << outputarray[i] << " ";
      cout << outputarray[i] << " ";
   }
   sout.close();
}




//this is main function .

int main() {

   cout << "*** Welcome to Cailyn's Sorting Program ***" << endl;
   cout << "Enter the first input file name: ";
   string filenamen;
   cin >> filenamen;
   fstream filestream;
   string filetext;
   
   //fail about thisfiile.
   //I got help from stackoverflow to solve AU server problem
   filestream.open(filenamen.c_str());
   if (filestream.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   int inputArray[99];
   int Myfffirstsize = readfile(inputArray, filestream);

   
   
   //this is the list of nubmer.
   cout << "The list of " << Myfffirstsize << " numbers in file " << filenamen << " is:" << endl;
   for (int i = 0; i < Myfffirstsize; i++) {
      cout << inputArray[i] << endl;
   } 
   filestream.close();
   
   
   //second file
   cout << "\nEnter the second input file name: "; 
   string nameaboutthis;
   cin >> nameaboutthis;
   string filetext1;
   //I got help from stackoverflow to solve AU server problem
   filestream.open(nameaboutthis.c_str());
   if (filestream.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   
   
   int Myfiletotalsize = Myfffirstsize + readfile(inputArray+Myfffirstsize, filestream);
   filestream.close();
   cout << "The list of " << Myfiletotalsize - Myfffirstsize << " numbers in file " << nameaboutthis << " is:" << endl;
   for (int P = Myfffirstsize; P < Myfiletotalsize; P++) {
      cout << inputArray[P] << endl;
   }
   //final 
   sort(inputArray, Myfiletotalsize);
   ofstream outstream;
   writefile(inputArray, Myfiletotalsize, outstream);
   cout << " " << endl;
     //Write file
    //part of 3 Goodbye code.
   string file;
   cout << "Enter the output file name: ";
   cin >> file;
   
   cout << "*** Please check the new file - " << file << " ***"<<endl;
   cout << "*** Goodbye. ***"<<endl;
   
   
   return 0;

}