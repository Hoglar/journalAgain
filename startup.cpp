#include <iostream>
#include <string_view>
#include <limits>
#include <string>

#include "startup.h"
#include "user.h";

// En funksjon som henter navn, dette være fra database eller en løsning som er enklere. 
// Den returner så dette navnet. Enkelt og greit. 


// Denne funksjonen skal kjøre på startup. det skal vise litt detaljer om navn på eier, dagens dato. 
// Så litt om status på checklister og sånn. 

// Lurer på om jeg kan gjøre noe med skrift farger og sånnt.
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

	// Er klar for å finne mere statuss

}