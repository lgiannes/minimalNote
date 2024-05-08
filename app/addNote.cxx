//
// Created by Lorenzo Giannessi on 06.05.2024.
//

#include "../inc/Notebook.hxx"
#include <fstream>

int main(int argc, char**  argv){

  // load the default notebook (from env var)
  // the arguments are: note tag, note text
  // append note to the notebook
  // if there is only one argument, the note tag is understood as an incrementing number "note_#" where the number is the number of notes in the notebook + 1

  bool tagIsNumber = false;

  if(argc < 2){
    std::cerr << "Usage: " << argv[0] << " <note tag> <note text>" << std::endl;
    std::cerr << "Or: " << argv[0] << " <note text>" << std::endl;
    return 1;
  }
  if(argc == 2){
    tagIsNumber = true;
  }else if(argc == 3){
    tagIsNumber = false;
  }else{
    std::cerr << "Usage: " << argv[0] << " <note tag> <note text>" << std::endl;
    std::cerr << "Or: " << argv[0] << " <note text>" << std::endl;
    return 1;
  }

  // get the notebook name from the environment variable
  const char * notebookNameChar = std::getenv("MY_NOTEBOOK");
  if( not notebookNameChar ){
    std::cerr << "Environment variable MY_NOTEBOOK not set!! Consider running source setup.sh" << std::endl;
    return 1;
  }
  std::string notebookName = std::getenv("MY_NOTEBOOK");
  if( not std::getenv("MY_NOTEBOOK") ){
    std::cerr << "Environment variable MY_NOTEBOOK not set!! Consider running source setup.sh" << std::endl;
    return 1;
  }

  Notebook notebook(notebookName);

  // todo: count the number of notes in the notebook (if note tag is not given)
  // todo: check if the note tag is already in the notebook (if note tag is given)
  // todo: finally: append the note to the notebook

  if(tagIsNumber) {
    // get the number of notes in the notebook
    int noteNumber = notebook.getNumNotes();
    std::string tag = "note_" + std::to_string(noteNumber + 1);
    std::string note = argv[1];
    // debug
    std::cout << "There are " << noteNumber << " notes in the notebook." << std::endl;
    std::cout << "Adding note with tag " << tag << " and text " << note << std::endl;
    notebook.add(tag, note);
  }else{
    std::string tag = argv[1];
    std::string note = argv[2];
    // debug
    std::cout << "Adding note with tag " << tag << " and text " << note << std::endl;
    notebook.add(tag, note);
  }



  return 0;
}