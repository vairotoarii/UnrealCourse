/*This is the cconsole executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame Class.*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
void PrintIntro();
void PlayGame();
FText GetValidGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of ?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	//TODO change from FOR to WHILE loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetValidGuess(); // TODO make loop checking valid

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;

		std::cout << "Your guess was : " << Guess << std::endl;
		std::cout << std::endl;
	}


	// TODO Add a game summary
}


// Loop continually until the user gives a valid guess.
FText GetValidGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do{
		// Get a guess from the player
		std::cout << "Try " << CurrentTry << ". Enter your guess : ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::Ok); // Keep looping until we get no errors

}

bool AsktoPlayAgain()
{
	std::cout << "Do you want to play again (Y/N) ?" << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response [0] == 'Y') || (Response [0] == 'y');
	std::cout << std::endl;
	
}
