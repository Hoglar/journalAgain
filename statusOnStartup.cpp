#include <iostream>
#include <string_view>
#include "statusOnStartup.h"
#include "user.h";

// For tid
// Lage en egen funksjon som henter tid?


// En funksjon som henter navn, dette v�re fra database eller en l�sning som er enklere. 
// Den returner s� dette navnet. Enkelt og greit. 





// Denne funksjonen skal kj�re p� startup. det skal vise litt detaljer om navn p� eier, dagens dato. 
// S� litt om status p� checklister og s�nn. 

// Lurer p� om jeg kan gj�re noe med skrift farger og s�nnt.
void statusOnStartup()
{
	if (checkUser())
	{
		std::cout << "Good day! " << getUser() << '.' << '\n';
	}
	else
	{
		createNewUser();
	}

	
}