#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values, initialised to zero
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{

public :
	FBullCowGame(); // Constructor

	
	int32 GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make more rich return value.
	bool CheckGuessValidity(std::string);//TODO make more rich return value.
	FBullCowCount SubmitGuess(FString);

// Please try and ignore this and focus on the interface above.
private :
	// See constructor for initialisation
	int MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};