// Project Milestone 02
// Jizzelle Cardenas
// March 21, 2019
// This project contains the implementation for the TuffyNotes project milestone 03
// The program keeps track of notes entered.

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
void Note::listNotes(int nums[], int size);
void Note::viewNotes(int nums[], int size);
