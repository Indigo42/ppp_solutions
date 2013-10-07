/*
    Description:        This is a game that tries to guess the user's number.
                        It is a solution for Chapter 4, Exercise 4 of
                        "Programming: Principles and Practice Using C++" by
                        Bjarne Stroustrup.
                        
    Algorithms:         guess_number() uses a binary search algorithm.
*/

#include <iostream>
#include <stdexcept>    // std::runtime_error

void guess_number(int min, int max);

int main()
{
    try {
        const int min = 1;
        const int max = 100;

        std::cout << "Think of a number (integer) between " << min << " and "
            << max << " . . .\n";
        guess_number(min, max);

        return 0;
    }
    catch (std::runtime_error& e) {
        std::cerr << "A runtime error has occurred: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An exception has occurred.\n";
        return 2;
    }
}

void guess_number(int min, int max)
{
    int questions_asked = 0;    // Number of questions asked.
    while (min < max) {
        int middle = (min + max) / 2;

        char reply = ' ';
        std::cout << "Is your number less than " << middle + 1 << "? (y/n) ";
        std::cin >> reply;

        if (reply == 'y' || reply == 'Y')
            max = middle;
        else if (reply == 'n' || reply == 'N')
            min = middle + 1;
        else
            throw std::runtime_error("You must enter \"y\" or \"n\" "
                                     "(without quotation marks).");

        // Show the current search range.
        std::cout << '[' << min << ", " << max << "]\n";

        ++questions_asked;
    }
    std::cout << "Your number: " << min << '\n';
    std::cout << "Questions asked: " << questions_asked << '\n';
}
