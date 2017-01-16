#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{

public :
	FBullCowGame(); // Constructor

	
	int32 GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make more rich return value.
	bool CheckGuessValidity(std::string);//TODO make more rich return value.
	// Povide a method for counting bulls & cows, and increasing try


// Please try and ignore this and focus on the interface above.
private :
	// See constructor for initialisation
	int MyCurrentTry;
	int32 MyMaxTries;

};