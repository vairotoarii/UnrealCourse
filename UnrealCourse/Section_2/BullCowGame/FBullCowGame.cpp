#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)// If the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; // return an error
	} 
	else if (false) // If the guess isn't all lowercase, return error
	{
		return EGuessStatus::Not_Lowercase;  // return an error
	}
	else if (Guess.length() != GetHiddenWordLength()) // If the guess lenght is wrong
	{
		return EGuessStatus::Wrong_Length;// return an error
	}
	else
	{
		return EGuessStatus::Ok;
	}
	  
	
	  

}

// receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	
	// loop throught all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) // if they match then
			{
				if (MHWChar == GChar) // if they're in the same place
				{ 
					BullCowCount.Bulls++; // increment bulls			
				}
				else //else
				{
					BullCowCount.Cows++; // increment cows
				}				
			}
		}
	}
	return BullCowCount;
}
