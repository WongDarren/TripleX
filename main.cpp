#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty)
{
  cout << "\n\nYou are a secret agent breaking into level " << Difficulty;
  cout << " secure server room . . . \nEnter the correct code to continue . . . \n\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  cout << "There are 3 numbers in the code \n";
  cout << "\nThe codes add up to: " << CodeSum;
  cout << "\nThe codes multiply to give: " << CodeProduct << endl;

  int GuessA, GuessB, GuessC;

  cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    cout << "\n***** Well done! You have extracted a file! Keep going! *****\n";
    return true;
  }
  else
  {
    cout << "\n***** You entered the wrong code! Be careful! Try again. *****\n";
    return false;
  }
}

int main()
{
  srand(time(NULL)); // create new random sequence based on time of day

  int Difficulty = 1;
  const int MaxDifficulty = 10;

  while (Difficulty <= MaxDifficulty)
  {
    bool bLevelComplete = PlayGame(Difficulty);

    cin.clear();  // Clears any errors
    cin.ignore(); // Discards the buffer

    if (bLevelComplete)
    {
      ++Difficulty;
    }
  }

  cout << "\n***** Great work agent! You got all the files! Now get out of there! *****\n";

  return 0;
}