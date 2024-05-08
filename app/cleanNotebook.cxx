//
// Created by Lorenzo Giannessi on 06.05.2024.
//


#include "../inc/Notebook.hxx"
#include <iostream>
#include <fstream>

int main(int argc, char**  argv){

  //if no arguments: get the notebook from teh environment variable (default)
  // if there's an argument, understand the argumet as the notebook name
  if(argc == 2){
    const char* folderPath = std::getenv("NOTEBOOKS_FOLDER");
    if(not folderPath){
      std::cerr << "Environment variable NOTEBOOKS_FOLDER not set!! Consider running source setup.sh" << std::endl;
      return 1;
    }
    if(std::string(folderPath).empty()){
      std::cerr << "Environment variable NOTEBOOKS_FOLDER not set!! Consider running source setup.sh" << std::endl;
      return 1;
    }
    std::string notebookName = folderPath+std::string(argv[1]);
    Notebook notebook(notebookName);
    return 0;
  }else if(argc > 2){
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  // get notebook name from environment variable
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

  // check that the file exists
  std::ifstream fileCheck(notebookName);
  if(not fileCheck.is_open()){
    std::cerr << "File " << notebookName << " does not exist. Run createNotebook to create it." << std::endl;
    return 1;
  }

  Notebook notebook(notebookName);
  notebook.clean();
  return 0;
}