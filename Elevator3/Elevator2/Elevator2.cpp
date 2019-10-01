// Elevator2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Elevator2 tasks: Allow for multiple floors to be inputted in quick succession during the time it takes for the elevator to travel

#include "pch.h"
#include <iostream>
//#include "Elevator2.h"

void Elevator()
{
	int * currentFloor = (int*)malloc(sizeof(int));
	*currentFloor = 1;

	int * temp = (int*)malloc(sizeof(int));

	int * floors = (int*)malloc(10 * sizeof(int));
	
	for (int i = 0; i < 10; i++)
	{
		floors[i] = i + 1;
	}

	const int numberOfChoices = 4;
	int * selections = (int*)malloc(numberOfChoices * sizeof(int));

	int * chosenFloor = (int*)malloc(sizeof(int));
	
	printf("Current Floor: ", *currentFloor);
	printf("%d", *currentFloor);
	printf("\n");
	printf("Please select your %d ", numberOfChoices);
	printf("destinations from floors 1 through 10. Press enter after each number.");
	printf("\n");
	printf("Exit(e)");
	printf("\n");

	for (int i = 0; i < numberOfChoices; i++)
	{
		scanf_s("%d", &selections[i]);
	}

	for (int i = 0; i < numberOfChoices - 1; i++)
	{
		for (int j = i + 1; j < numberOfChoices; j++)
		{
			if (i != j)
			{
				if (selections[i] > selections[j])
				{
					*temp = selections[i];
					selections[i] = selections[j];
					selections[j] = *temp;
				}
			}
		}
	}

	for (int i = 0; i < numberOfChoices; i++)
	{

		*chosenFloor = selections[i];

		if ((*chosenFloor > *currentFloor) && (*chosenFloor < 11))//up
		{
			printf("Going up.");
			printf("\n");

			for (int i = *currentFloor - 1; i <= *chosenFloor - 1; i++)
			{
				printf("%d\n", floors[i]);
			}
			*currentFloor = *chosenFloor;
		}
		else if ((*chosenFloor < *currentFloor) && (*chosenFloor > 0))//down
		{
			printf("Going down.");
			printf("\n");

			for (int i = *currentFloor - 1; i >= *chosenFloor - 1; i--)
			{
				printf("%d\n", floors[i]);
			}
			*currentFloor = *chosenFloor;
		}
		else if (*chosenFloor = *currentFloor)
		{
			printf("You are already on this floor. Please select a destination.");
			printf("\n");
		}
		else
		{
			printf("Entry invalid, try again.");
			printf("\n");
		}
		*currentFloor = *chosenFloor;
	}

	free(currentFloor);
	free(temp);
	free(floors);
	free(selections);
	free(chosenFloor);
}

int main()
{
	Elevator();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
