// Project Milestone 02
// Jizzelle Cardenas
// March 21, 2019
// This project contains the implementation for the
// TuffyNotes project milestone 02
// The program repeatedly asks a user to create a note
// until exit is selected.
// The program also keeps track of all notes entered.

#include <string>

const int MAX_NUMBER_NOTES = 100;

class Note
{
  private:
    std::string title_;
    std::string body_;

  public:
    std::string getTitle() { return title_; }
    std::string getBody() { return body_; }

    void setTitle(std::string t) { title_ = t; }
    void setBody(std::string b) { body_ = b; }
};

// ask user to provide a note
Note createNote();
void listNotes();
void viewNotes();
