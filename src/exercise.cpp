#include <iostream>
#include "compute_score.h"

long compute_scores()
{
  long scores = 0;

  const std::string filepath{"../src/names.txt"}; 
  std::vector<std::string> name_list;

  read_file(filepath, name_list);
  sort_file(name_list);
  scores = find_total_score(name_list);

  return scores;
}

int main()
{
  auto scores = compute_scores();
  std::cout << "The total sum of all name scores is " << scores << std::endl;
}