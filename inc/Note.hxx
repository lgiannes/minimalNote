//
// Created by Lorenzo Giannessi on 29.04.2024.
//

#ifndef NOTE_NOTE_HXX
#define NOTE_NOTE_HXX

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <chrono>
#include <ctime>

class Note {
public:
    Note();
    ~Note();
    void setDone();
    void setUndone();
    void setDatetime(const std::string &datetime);
    void setTag(const std::string &tag);
    void edit(const std::string &note);
    std::string getTag() const;
    std::string getNote() const;
    std::string getDatetime() const;
    std::string getStatus() const;

    enum Status
    {
        UNDONE,
        DONE
    };

    void setStatus(Status status);
    void setStatus(const std::string status);


private:
    std::string _tag;
    std::string _note;
    std::string _datetime;
    Note::Status _status;

};


#endif //NOTE_NOTE_HXX
