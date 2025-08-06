#pragma once

#include <string>
#include <ctime>

struct ChecklistItem
{
	std::string title;
	std::string description;
	std::string creationDate;
	std::time_t creationTimestamp;
	int completedDays;
};

void createChecklist();
void displayChecklist();
void checkOffList();
void removeChecklistItem();