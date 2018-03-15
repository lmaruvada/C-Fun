#include <iostream>
#include <random>
using namespace std;

int printRandom(){
  //Used to initialize (seed) the random number generator engine.
  random_device seed{};

  //The random number generator
  mt19937 engine{seed()};
  
  // Uniformly distribute random numners n [1..10]
  uniform_int_distribution<> dis{1,10};

  // Generate a random Integer
  int x{ dis(engine) };

  return x;
}

int main() {
  // Code to generate random numbers. 
  random_device seed{};
  mt19937 engine{seed()};
  uniform_int_distribution<> dis{1,10};

  constexpr int  questionCount{3};
  int correctAnswers{0};

  for(int i =0; i< questionCount;i++){
    int a{dis(engine)};
    int b{dis(engine)};

    cout << a << " * " << b << " = ? ";
   
    int userAnswer{};
    cin >> userAnswer;

    if(userAnswer == (a*b)){
      cout << "Correct!\n";
      correctAnswers++;
    } else {
      cout << "Wrong!\n";
    }
  } 
  cout << " Correct answers: " << correctAnswers << endl;
  if(correctAnswers == questionCount){
    cout << "Congrats! Your answers are all correct!\n";
  }

}
