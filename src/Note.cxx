//
// Created by Lorenzo Giannessi on 29.04.2024.
//

#include "../inc/Note.hxx"
#include <iostream>
#include <string>

Note::Note() {
  _tag = "";
  _note = "";
  _datetime = "";
  _status = UNDONE;
}

Note::~Note() = default;

void Note::setDone() {
  _status = DONE;
}

void Note::setUndone() {
  _status = UNDONE;
}

void Note::setTag(const std::string &tag) {
  _tag = tag;
}

void Note::edit(const std::string &note) {
  _note = note;
}

void Note::setDatetime(const std::string &date) {
  _datetime = date;
}


void Note::setStatus(Status status) {
  _status = status;
}

void Note::setStatus(const std::string status) {
  if (status == "DONE") {
    _status = DONE;
  } else if(status == "UNDONE"){
    _status = UNDONE;
  }else{
    std::cerr << "Invalid input status: " << status << std::endl;
  }
}

std::string Note::getTag() const {
  return _tag;
}

std::string Note::getNote() const {
  return _note;
}

std::string Note::getDatetime() const {
  return _datetime;
}

std::string Note::getStatus() const {
  if (_status == DONE) {
    return "DONE";
  } else {
    return "UNDONE";
  }
}

