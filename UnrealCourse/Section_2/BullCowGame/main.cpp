#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AsktoPlayAgain();

FBullCowGame BCGame; //Instantiate a new game

// The entry point for our application

int main()
{
	std::cout << BCGame.GetCurrentTry();
	bool bPlayAgain = false;
	do
	{
		PrintIntro();

		PlayGame();

		bPlayAgain = AsktoPlayAgain();

	}

	while (bPlayAgain);
	{

	}

	return 0; // Exit the application
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of ?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	//TODO change from FOR to WHILE loop once we are validating tries
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = "";
		Guess = GetGuess(); // TODO make loop checking valid

		//Submit valid guess to the game
		// Print number of bulls and cows

		std::cout << "Your guess was : " << Guess << std::endl;
		std::cout << std::endl;
	}


	// TODO Add a game summary
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	// Get a guess from the player

	std::cout << "Try " << CurrentTry << ". Enter your guess : ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;

}

bool AsktoPlayAgain()
{
	std::cout << "Do you want to play again (Y/N) ?" << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response [0] == 'Y') || (Response [0] == 'y');
	std::cout << std::endl;
	
}
