// Trenger jeg , eller kan jeg gj�re det s�nn her. Gj�re alts slik komblisert tid greier her,
// Lage funskjoner som fikser det jeg trenger, s� jeg kan bruke det litt her og der. 

#include <iostream>
// Get and maipulate time/date
#include <ctime>
// Format time output with put_time
#include <iomanip>
// Convert formatted time into a string
#include <sstream>


// Forsto ikke alt her du! Men enkelt og greit. F�r datoen slik jeg vil, som en string jeg kan lagre og bruke.
std::string getTodayDate()
{
	std::time_t t = std::time(nullptr);
	std::tm now;
	localtime_s(&now, &t);

	std::ostringstream oss;
	oss << std::put_time(&now, "%d-%m-%Y");

	return oss.str();
}

// Trenger og � kunne hente tid n� som timestamp.
std::time_t creationTimestamp()
{
	std::time_t now = std::time(nullptr);
	return now;
}