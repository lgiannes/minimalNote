//
// Created by Lorenzo Giannessi on 29.04.2024.
//

#include "../inc/Notebook.hxx"
#include <fstream>

Notebook::Notebook(std::string filename)
: _filename(filename), _divider("--------------------------------------------------") {
  // check if file exists, if it doesn't suggest ot run createnotebook
  // open file and load notes
    std::ifstream file(filename);
    int countNotes = 0;
    if (file.is_open()) {
        std::string tag, note, datetime, divider;
        Note::Status status;
        // skip first three lines (title of the notebook)
        std::string line;
        for (int i = 0; i < 3; i++) {
            std::getline(file, line);
        }
        // read file line by line
        // first line: tag,
        // second line: date, time
        // third line: note
        // fourth line: string identifying status
        // fifth line: divider
        while (std::getline(file, tag)){
            std::getline(file, datetime);
            std::getline(file, note);
            std::string status_str;
            std::getline(file, status_str);
            if (status_str == "DONE") {
                status = Note::Status::DONE;
            } else {
                status = Note::Status::UNDONE;
            }
            std::getline(file, divider);
            // the number of divider lines is the same as the number of notes
            countNotes++;
            Note n;
            n.setTag(tag);
            n.setDatetime(datetime);
            n.edit(note);
            n.setStatus(status);
            _notes.push_back(n);
        }
        file.close();
    }else{
        std::cerr << "File " << filename << " does not exist. Run createNotebook to create it." << std::endl;
    }

    this->_filename = filename;
    std::cout << "Notebook " << filename << " loaded." << std::endl;
}


void Notebook::showAll() {
    // show title (first three lines)
    std::ifstream
    file(_filename);
    std::string line;
    for (int i = 0; i < 3; i++) {
        std::getline(file, line);
        std::cout << line << std::endl;
    }

    std::cout << "Notes in this notebook: " << _notes.size() << std::endl;
    for (const auto &note : _notes) {
        std::cout << _divider << std::endl;
        std::cout << "Tag: " << note.getTag() << std::endl;
        std::cout << "Date: " << note.getDatetime() << std::endl;
        // wrap the note to 80 characters line length
        std::string note_str = note.getNote();
        std::cout << "Note: " << std::endl;
        for (int i = 0; i < note_str.size(); i += 80) {
            std::cout << ">  " << note_str.substr(i, 80) << std::endl;
        }
        std::cout << "Status: " << note.getStatus() << std::endl;
    }
    std::cout << _divider << std::endl;
}


void Notebook::add(const Note &n) {
  _notes.push_back(n);
  // write to file
  std::ofstream
  file(_filename, std::ios::app);
  file <<  n.getTag() << std::endl;
  file <<  n.getDatetime() ;
  file <<  n.getNote() << std::endl;
  file <<  n.getStatus() << std::endl;
  file << _divider << std::endl;
  file.close();
}

void Notebook::add(const std::string &tag, const std::string &note) {
  Note n;
  n.setTag(tag);
  n.edit(note);
  // get current time and date
  auto now = std::chrono::system_clock::now();
  std::time_t now_show = std::chrono::system_clock::to_time_t(now);
  n.setDatetime(std::ctime(&now_show));
  _notes.push_back(n);
  // write to file
  std::ofstream
  file(_filename, std::ios::app);
  file << n.getTag() << std::endl;
  file << n.getDatetime() ;
  file << n.getNote() << std::endl;
  file << n.getStatus() << std::endl;
  file << _divider << std::endl;
  file.close();
}


void Notebook::clean() {
  // remove all notes
  _notes.clear();
  // read first three lines of the file
  std::ifstream
  file(_filename);
  std::string line;
  std::string title1, title2, title3;
  for (int i = 0; i < 3; i++) {
    std::getline(file, line);
    if (i == 0) {
      title1 = line;
    } else if (i == 1) {
      title2 = line;
    } else {
      title3 = line;
    }
  }
  file.close();
  // write the title back to the file
  std::ofstream
  fileout(_filename, std::ios::trunc);
  fileout << title1 << std::endl;
  fileout << title2 << std::endl;
  fileout << title3 << std::endl;
  fileout.close();

  std::cout << "Notebook " << _filename << " cleaned up." << std::endl;
}
