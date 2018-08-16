#include<iostream>
#include<string>

// FUNCTION DECLARATION (DECLARE YOUR FUNCTIONS HERE FIRST)

void RepeatGuess(std::string Guess);
void PrintIntro(int *LENGTH);
std::string GetGuess();
bool logic(std::string Guess, std::string ANSWER);

// MAIN FUNCTION

int main()
{
	const std::string ANSWER = "Coding";
	int WORD_LENGTH = ANSWER.length();
	constexpr int NO_OF_TURNS = 6;
	bool repeat = false;
	PrintIntro(&WORD_LENGTH);
	for (int i = 0; i < NO_OF_TURNS; i++)
	{
		if (repeat == false)
		{
			std::string Guess = GetGuess();
			repeat = logic(Guess, ANSWER);
			//RepeatGuess(Guess);
		}
		else
		{
			return 0;
		}
	}
	return 0;
}


// FUNCTION DEFINATION (DEFINATION OF EVERY FUNCTION DECLARED IN FUNCTION DECLARATION PART)

void PrintIntro(int *LENGTH)
{
	// Introduction
	//constexpr int WORD_LENGTH = ANSWER.length();
	std::cout << "Welcome to Bulls and Cows....." << std::endl;
	std::cout << "Can yout guess the " << *LENGTH << " letter isogram?" << std::endl << std::endl;
}

std::string GetGuess()
{
	// Making a Guess

	std::cout << "Enter your Guess: ";
	std::string Guess;
	std::getline(std::cin, Guess);

	return Guess;
}

/*void RepeatGuess(std::string Guess)
{
	// Repeting the Guess

	std::cout << "Your Guess was: " << Guess << std::endl << std::endl;
}*/

bool logic(std::string Guess, std::string ANSWER)
{
	int bulls = 0;
	int cows = 0;
	// If Correct

	if (Guess == ANSWER)
	{
		std::cout << "Voala!!!";
		return true;
	}
	// Checking String length
	
	if (Guess.length() != ANSWER.length())
	{
		std::cout << "String either too long or too Short";
		return false;
	}

	// Checking for Bulls and Cows

	for (int i = 0; i < ANSWER.length(); i++)
	{
		if (Guess[i] == ANSWER[i])
		{
			bulls++;
		}
		for (int j = 0; j < ANSWER.length(); j++)
		{
			if (Guess[i] == ANSWER[j])
			{
				cows++;
			}
		}
	}

	std::cout << "Bulls = " << bulls << std::endl << "Cows = " << cows << std::endl << std::endl;

	return false;

}
