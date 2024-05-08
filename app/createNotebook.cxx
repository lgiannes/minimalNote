//
// Created by Lorenzo Giannessi on 04.05.2024.
//

#include "../inc/Notebook.hxx"
#include <fstream>


int main(int argc, char**  argv){
    if(argc != 2){
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    // get teh default fodler path from env variable
    const char* folderPath = std::getenv("NOTEBOOKS_FOLDER");
    if(not folderPath){
        std::cerr << "Environment variable NOTEBOOKS_FOLDER not set!! Consider running source setup.sh" << std::endl;
        return 1;
    }
    if(std::string(folderPath).empty()){
        std::cerr << "Environment variable NOTEBOOKS_FOLDER not set!! Consider running source setup.sh" << std::endl;
        return 1;
    }

    std::string notebookFileName = std::string(folderPath) + "/" + argv[1];
    std::cout<< "Creating text file " << notebookFileName << std::endl;

    // check if it already exists
    std::ifstream fileCheck(notebookFileName);
    if(fileCheck.is_open()){
        std::cerr << "File " << argv[1] << " already exists. Choose a different name." << std::endl;
        return 1;
    }

    std::ofstream file(notebookFileName);
    if(!file.is_open()){
        std::cerr << "Error opening file " << argv[1] << std::endl;
        return 1;
    }else{
      std::cout<< "Creating text file " << argv[1] << std::endl;
      // make the title
      int headerLength = 60;
      std::string header1 = std::string(headerLength, '|');
      std::string title = argv[1];
      auto now = std::chrono::system_clock::now();
      std::time_t now_show = std::chrono::system_clock::to_time_t(now);
      title = title + ": Created on " + std::ctime(&now_show);
      // do not include the newline character
      for(int i=0;i<title.length();i++) if(title[i]=='\n') title.erase(title.begin()+i);

      int titleLength = title.size();
      std::string header2 = "|" + std::string((headerLength - titleLength)/2-1, ' ');
      std::string header3 = std::string((headerLength - titleLength)/2-1, ' ') + "|";

      file << header1 << std::endl;
      file << header2 << title << header3 << std::endl;
      file << header1 << std::endl;
    }
    file.close();

    std::cout<<"Successfully created notebook file at: "<< notebookFileName << std::endl;

    // print out the generated file
    std::ifstream filePrint(notebookFileName);
    std::string line;
    while(std::getline(filePrint, line)){
        std::cout << line << std::endl;
    }


    return 0;
}