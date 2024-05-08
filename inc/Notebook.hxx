//
// Created by Lorenzo Giannessi on 29.04.2024.
//

#ifndef NOTE_NOTEBOOK_HXX
#define NOTE_NOTEBOOK_HXX

#include <vector>
#include "Note.hxx"

class Notebook {
private:
    std::vector<Note> _notes;
    std::string _filename;
    const std::string _divider;

public:
    Notebook(std::string filename);
    ~Notebook() = default;
    inline void setFilename(const std::string &filename){_filename = filename;};
    void add(const Note &note);
    void add(const std::string &tag, const std::string &note);
    void remove(const std::string &tag);
    void removeAll();
    void showAll();
    void show(const std::string &tag);
    int getNumNotes(){return _notes.size();};
    void clean();

};


#endif //NOTE_NOTEBOOK_HXX
