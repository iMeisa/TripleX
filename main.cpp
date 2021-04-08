#include <iostream>
#include <ctime>

int RandValue(int min, int max) {

    int NewValue = (rand() % max) + min;
//    std::cout << "New Value: " << NewValue << std::endl;
    return NewValue;
}

bool PlayGame(int difficulty) {
    std::cout << "\n\nYou are a secret agent breaking into a secure server room\n";
    std::cout << "You need to enter the correct codes to continue...\n";

    int CodeA = RandValue(1, difficulty);
    int CodeB = RandValue(1, difficulty);
    int CodeC = RandValue(1, difficulty);

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

//    std::cout << CodeA << CodeB << CodeC;

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;

    std::cout << "\n> ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "Grats" << std::endl;
        return true;
    } else {
        std::cout << "Nope" << std::endl;
        return false;
    }

}

int main() {
    srand(time(nullptr));

    int Difficulty = 3;
    int MaxDifficulty = 10;

    while(Difficulty <= MaxDifficulty) {
        bool WonGame = PlayGame(Difficulty);

        if (WonGame) {
            Difficulty++;
        }
    }
    return 0;
}
