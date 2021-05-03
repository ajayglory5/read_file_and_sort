#include <iostream>
#include <fstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>

#include "compute_score.h"

void read_file(std::string file, std::vector<std::string> &names){
  std::fstream inputFile(file);

  if(!inputFile.is_open()){
    std::cout << "Error in opening the given file!" << std::endl;
  }
  else {
    std::cout << "Started to parse the file..." << std::endl;
    std::string name;
    while(std::getline(inputFile, name)){
        boost::split(names, name, boost::is_any_of(","));
    }
    inputFile.close();
  } 
}

void sort_file(std::vector<std::string> &names){
  std::sort(names.begin(), names.end());
}

long obtain_name_score(std::string &name){
    long score{0}; 
    int i{1}; 
    // ignoring the first and the last inverted commas
    while((name.size()-1) > i){
        score += int(name[i++]) - SCORE; 
    } 
    return score;
}

long find_total_score(std::vector<std::string> &names){
  long total_score{0}; 
  int position{1}; 
  for(auto &name: names){
    total_score += (position * obtain_name_score(name));
    position++;
  }
  return total_score; 
}