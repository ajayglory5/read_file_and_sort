#include <vector>

constexpr int SCORE{64};  

void read_file(std::string file, std::vector<std::string> &names);
void sort_file(std::vector<std::string> &names);
long obtain_name_score(std::string &name);
long find_total_score(std::vector<std::string> &names);
