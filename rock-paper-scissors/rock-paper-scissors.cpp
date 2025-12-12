#include <iostream>

using namespace std;

enum enGameChoice { paper = 1, stone = 2, scissors = 3 };

enum enWinnerOrEqual { equitable = 0, playerwin = 1, computerwin = 2 };


int _F_RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void _P_ReadNumberOfRounds(int& howmanyrounds)
{
	do
	{
		cout << "Please enter how many rounds you want the game to be?\n";
		cin >> howmanyrounds;
	} while (howmanyrounds <= 0);
}

void _P_PlayerChoose(int& playerchoose)
{
	do
	{
		cout << "\nPlease enter your choosing... 1[Paper] 2[Stone] 3[scissors]: ";
		cin >> playerchoose;
	} while (playerchoose < 1 || playerchoose>3);
}

void _P_ComputerChoose(int& computerchoose)
{
	computerchoose = _F_RandomNumber(1, 3);
}

// We used procedure PlayerChoose and procedure ComputerChoose in this procedure
void _P_PlayerAndComputerChoose(int& playerchoose, int& computerchoose)
{
	_P_PlayerChoose(playerchoose);
	_P_ComputerChoose(computerchoose);
}

void _P_TurnChoosingsToEnumAndStrings(int playerchoose, int computerchoose, enGameChoice& ENplayerchoosing, enGameChoice& ENcomputerchoosing, string& STplayerchoosing, string& STcomputerchoosing)
{
	switch (playerchoose)
	{
	case 1:
	{
		ENplayerchoosing = paper;
		STplayerchoosing = " Paper ";

		break;
	}
	case 2:
	{
		ENplayerchoosing = stone;
		STplayerchoosing = " Stone ";

		break;
	}
	case 3:
	{
		ENplayerchoosing = scissors;
		STplayerchoosing = " Scissors ";


		break;
	}
	}
	switch (computerchoose)
	{
	case 1:
	{
		ENcomputerchoosing = paper;
		STcomputerchoosing = " Paper ";
		break;
	}
	case 2:
	{
		ENcomputerchoosing = stone;
		STcomputerchoosing = " Stone ";
		break;
	}
	case 3:
	{
		ENcomputerchoosing = scissors;
		STcomputerchoosing = " Scissors ";
		break;
	}
	}
}

void _P_FigureWhoWon(enWinnerOrEqual& ENresults, enGameChoice ENplayerchoosing, enGameChoice ENcomputerchoosing)
{
	if (ENplayerchoosing == ENcomputerchoosing)
	{
		ENresults = equitable;
	}

	else
	{
		if ((ENplayerchoosing == paper && ENcomputerchoosing == stone) || (ENplayerchoosing == stone && ENcomputerchoosing == scissors) || (ENplayerchoosing == scissors && ENcomputerchoosing == paper))
		{
			ENresults = playerwin;
		}
		else
		{
			ENresults = computerwin;
		}
	}
}

void _P_TellPlayerAndComputerChoose(string STplayerchoosing, string STcomputerchoosing)
{
	cout << "\nYour choosing is: " << STplayerchoosing;
	cout << "\nComputer choosing is: " << STcomputerchoosing;
}

void _P_ColorScreenAndTellResults(string STplayerchoosing, string STcomputerchoosing, enWinnerOrEqual ENresults)
{
	_P_TellPlayerAndComputerChoose(STplayerchoosing, STcomputerchoosing);

	if (ENresults == equitable)
	{
		cout << "\n\nRound Results: [Equitable]\n";
		system("color 6F");//Yellow
	}
	else if (ENresults == playerwin)
	{
		cout << "\n\nRound Results: [You Win]\n";
		system("color 2F");//Green
	}
	else if (ENresults == computerwin)
	{
		cout << "\n\nRound Results: [Computer Win]\n";
		system("color 4F");//Red
	}
}

void _P_ReadAndPrintTheRound(enWinnerOrEqual& ENresults)
{
	int playerchoose, computerchoose;

	enGameChoice ENplayerchoosing, ENcomputerchoosing;

	string STplayerchoosing, STcomputerchoosing;


	_P_PlayerAndComputerChoose(playerchoose, computerchoose);

	_P_TurnChoosingsToEnumAndStrings(playerchoose, computerchoose, ENplayerchoosing, ENcomputerchoosing, STplayerchoosing, STcomputerchoosing);

	_P_FigureWhoWon(ENresults, ENplayerchoosing, ENcomputerchoosing);

	_P_ColorScreenAndTellResults(STplayerchoosing, STcomputerchoosing, ENresults);
}

void _P_PlayChoosenNumberOfRounds(int& howmanyrounds, int& roundsplayerwin, int& roundscomputerwin, int& roundsequitable)
{
	roundsplayerwin = 0, roundscomputerwin = 0, roundsequitable = 0;

	enWinnerOrEqual ENresults;

	_P_ReadNumberOfRounds(howmanyrounds);
	for (int i = 1;i <= howmanyrounds;i++)
	{
		if (i == 1)
		{
			cout << "\n____________________________________________________\n";
		}

		cout << "\t\t_____Round " << i << "_____\n";
		_P_ReadAndPrintTheRound(ENresults);
		cout << "\n______________________________________________________\n";
		if (ENresults == playerwin)
		{
			roundsplayerwin++;
		}
		else if (ENresults == computerwin)
		{
			roundscomputerwin++;
		}
		else if (ENresults == equitable)
		{
			roundsequitable++;
		}
	}
}

void _P_DetermineTheWinner(int roundsplayerwin, int roundscomputerwin, string& whoisthewinner)
{
	if (roundsplayerwin == roundscomputerwin)
	{
		whoisthewinner = "No one";
	}
	else if (roundsplayerwin > roundscomputerwin)
	{
		whoisthewinner = "Player";
	}
	else if (roundsplayerwin < roundscomputerwin)
	{
		whoisthewinner = "Computer";
	}
}

void _P_PrintGameResults(int howmanyrounds, int roundsplayerwin, int roundscomputerwin, int roundsequitable, string whoisthewinner)
{
	cout << "\n\t\t________________________________________________________________________\n\n";
	cout << "\t\t\t\t\t+++ G A M E   O V E R +++";
	cout << "\n\t\t________________________________________________________________________\n\n";
	cout << "\t\t_____________________________[Game Results]_____________________________\n\n";
	cout << "\t\tGame Rounds        : " << howmanyrounds << "\n";
	cout << "\t\tPlayer won times   : " << roundsplayerwin << "\n";
	cout << "\t\tComputer won times : " << roundscomputerwin << "\n";
	cout << "\t\tDraw Times         : " << roundsequitable << "\n";
	cout << "\t\tFinal winner       : " << whoisthewinner;
	cout << "\n\t\t________________________________________________________________________\n";
}

void _P_ColorScreenWhenRestart(char restartornot)
{
	if (restartornot == 'y')
	{
		system("COLOR 0F");
	}
}

void _P_RestartGameOrNot(char& restartornot)
{
	cout << "\nDo you want to play again? (y,n)? ";
	cin >> restartornot;
	_P_ColorScreenWhenRestart(restartornot);
}


int main()
{
	srand((unsigned)time(NULL));

	char restartornot;

	do
	{
		int howmanyrounds, roundsplayerwin, roundscomputerwin, roundsequitable;
		string whoisthewinner;


		_P_PlayChoosenNumberOfRounds(howmanyrounds, roundsplayerwin, roundscomputerwin, roundsequitable);
		_P_DetermineTheWinner(roundsplayerwin, roundscomputerwin, whoisthewinner);

		_P_PrintGameResults(howmanyrounds, roundsplayerwin, roundscomputerwin, roundsequitable, whoisthewinner);
		_P_RestartGameOrNot(restartornot);

	} while (restartornot == 'y');

	return 0;
}