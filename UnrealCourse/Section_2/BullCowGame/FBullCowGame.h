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

enum class EWordStatuts 
{

	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,

};


class FBullCowGame
{

public :
	FBullCowGame(); // Constructor

	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatuts CheckGuessValidity(FString) const;//TODO make more rich return value.

	void Reset(); //TODO make more rich return value.
	FBullCowCount SubmitGuess(FString);

// Please try and ignore this and focus on the interface above.
private :
	// See constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};