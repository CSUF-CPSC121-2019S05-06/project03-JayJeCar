// Project Milestone 02
// Jizzelle Cardenas
// March 21, 2019
// This project contains the implementation for the TuffyNotes project milestone 03
// The program keeps track of notes entered.

#include <iostream>
#include <string>
#include "notebook.hpp"

// THe following are global functions

//This function has no parameters according to the solution from Project 02
Note createNote()
{
  std::string title, body;

  std::cout << "\nPlease enter the note's title: ";
  std::getline(std::cin, title);
  std::cout << "Please enter the note: ";
  std::getline(std::cin, body);

  Note note;
  note.setTitle(title);
  note.setBody(body);

  std::cout << "\nNote added!\n";

  return note;
}

void Note listNotes(int nums[], int size) //Second function implemented to list all notes
{
  createNote(); //Calling the first function within this function

  int sum = 0;
  const int sentinel_value = -1;

  std::cout << "Notes\n";
  for (int i = 0; i <= MAX_NUMBER_NOTES; i++)
  {
    if (nums[i] == sentinel_value)
    {
      std::cout << "No notes have been added.\n";
    }
    sum += nums[i];
    std::cout << (i+1) << ". " << nums[i] << std::endl;
  }
}

void Note viewNote (int nums[], int size) //Third function that uses second function to select and view a note
{
  int choice;
  listNotes(int nums[], int size); //Calling Second Function
  std::cout << "Please input note index: \n";
  std::cin >> choice;
  if ((choice != 0) && (choice <= MAX_NUMBER_NOTES))
  {
  std::cout << "[" << nums[choice+1] << "]" << std::endl;
  std::cout << note.getBody(nums[choice]);
  }
  else
  {
    std::cout << "Invalid note index." << std::endl;
  }
}
