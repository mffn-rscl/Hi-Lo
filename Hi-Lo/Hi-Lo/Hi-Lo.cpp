#include <iostream>
#include <random>
#include <cstdlib> // для функцій srand() і rand()
#include <ctime> // для функції time()
using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Рівномірно розподіляємо рандомне число в нашому діапазоні
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//алгоритм гри
bool playGame(int guesess, int number) 
{
    for (int count = 1; count <= guesess; count++)
    {
        cout << " Guess #" << count << " enter a number: ";
        int guess;
        cin >> guess;

        if (guess > number)
            cout << "Your guess is too high.";
        else if (guess < number)
            cout << "Your guess is too low.";
        else
            return true;
    }
    return false;
}

// запит на повторення гри
bool playAgain()
{
    char ch;
    do {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;
    } while (ch != 'n' && ch != 'y');

    return (ch == 'y');
}





int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    
    const int guesses = 7;


    do
    {
        int number = getRandomNumber(1, 100);

        cout << "Let's play a game.  I'm thinking of a number.  You have " << guesses << " tries to guess what it is.\n";
        
        bool won = playGame(guesses, number);
        if (won)
            cout << "Correct!  You win!\n";
        else
            cout << "Sorry, you lose.  The correct number was " << number << "\n";
    }
    while (playAgain());

    std::cout << "Thank you for playing.\n";
    return 0;
}

