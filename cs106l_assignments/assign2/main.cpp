
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <map>
#include <sstream>

std::string kYourName = "Kevin Yang"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
    std::ifstream ofs(filename);
    std::set<std::string> names;
    if (ofs.is_open())
    {
      std::string name;
      while (getline(ofs , name))
      {
        names.insert(name);
      }
    }
    ofs.close();
    return names;
}

bool check_initials(std::string base_name , std::string compare_name)
{
  if (base_name[0] != compare_name[0]) return false;
  std::string skip_string;
  char base_letter , compare_letter;
  std::istringstream iss_b(base_name);
  std::istringstream iss_c(compare_name);
  iss_b >> skip_string >> base_letter;
  iss_c >> skip_string >> compare_letter;
  return base_letter == compare_letter ? true : false;
  
}



/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> roster;
  for(const auto& student : students)
  {
    if (check_initials(name , student)) roster.emplace(&student);
  }
  return roster;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty())
  {
    std::cout << "NO MATCHES FOUND." << std::endl;
  }
  
  std::map<std::string , int> cc_count;
  std::pair<std::string , int> cc_max{"CHONG GE" , 0};
  while (!matches.empty())
  {
    for(const auto& letter : *(matches.front()))
    {
      if(letter == 'c')
      ++cc_count[*(matches.front())];
    }
    if (cc_count[*(matches.front())] >= cc_max.second)
    {
      cc_max = {*(matches.front()) , cc_count[*(matches.front())]};
    }
    matches.pop();
  }
  return cc_max.first;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
