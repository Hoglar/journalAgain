#include <iostream>
#include <string_view>
#include "statusOnStartup.h"


// En funksjon som henter navn, dette v�re fra database eller en l�sning som er enklere. 
// Den returner s� dette navnet. Enkelt og greit. 
std::string_view getUsername() 
{
	return "Martin";
}


// Denne funksjonen skal kj�re p� startup. det skal vise litt detaljer om navn p� eier, dagens dato. 
// S� litt om status p� checklister og s�nn. 

// Lurer p� om jeg kan gj�re noe med skrift farger og s�nnt.
void statusOnStartup()
{
	// F�r navn fra 
	std::cout << getUsername() << '\n';
}