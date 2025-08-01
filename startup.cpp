#include <iostream>
#include <string_view>
#include <limits>
#include <string>

#include "startup.h"
#include "user.h";

// En funksjon som henter navn, dette v�re fra database eller en l�sning som er enklere. 
// Den returner s� dette navnet. Enkelt og greit. 


// Denne funksjonen skal kj�re p� startup. det skal vise litt detaljer om navn p� eier, dagens dato. 
// S� litt om status p� checklister og s�nn. 

// Lurer p� om jeg kan gj�re noe med skrift farger og s�nnt.
void startup()
{
	if (!userExists())
	{
		// Lage ny user her
		std::cout << "Welcome, do you want to start a journal? y/n: ";
		char ans{};
		std::cin >> ans;
		if (ans == 'y')
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "What's your name? ";
			std::string name{};
			std::getline(std::cin, name);

			createNewUser(name);
		}
		else
		{
			std::cout << "Exiting program!\n";
			std::exit(1);
		}
	}
	
	// Fortsett program
	std::cout << "Good day, " << getUser() << "!\n";

	// Er klar for � finne mere statuss

}