#include <iostream>
#include <string_view>
#include "statusOnStartup.h"


// En funksjon som henter navn, dette være fra database eller en løsning som er enklere. 
// Den returner så dette navnet. Enkelt og greit. 
std::string_view getUsername() 
{
	return "Martin";
}


// Denne funksjonen skal kjøre på startup. det skal vise litt detaljer om navn på eier, dagens dato. 
// Så litt om status på checklister og sånn. 

// Lurer på om jeg kan gjøre noe med skrift farger og sånnt.
void statusOnStartup()
{
	// Får navn fra 
	std::cout << getUsername() << '\n';
}