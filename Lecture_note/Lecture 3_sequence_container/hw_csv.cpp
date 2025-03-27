#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define CSV "courses.csv"
#define CSV_OFFERED "result\\courses_o.csv"
#define CSV_NOT_OFFERED "result\\courses_n.csv"

struct Courses
{
    std::string title;
    size_t number_of_units;
    std::string quarter;
};

void parse_csv(std::string filename , std::vector<Courses>& courses)
{
    //process csv line by line and store the data into Course vector
    std::ifstream ifs(filename); 
    std::string line ; getline(ifs , line); //skip the first line

    std::string title , quarter; size_t num;
    while (getline(ifs , line))
    {
        //line -> string (xx , xx , xx) , put it into vector
        std::istringstream iss(line);
        getline(iss , title , ',');
        iss.ignore();
        iss >> num;
        getline(iss , quarter , ',');

        courses.emplace_back(title , num , quarter);   //before using emplace method , u have to ensure there is a constructor for the exactly type u declare
    }
    ifs.close();
}

void write_courses_offered(std::vector<Courses>& all_courses)
{
    //write offered courses to csv and remove them from the original vector
    std::ofstream ofs(CSV_OFFERED);
    ofs << "Title,Number of Units,Quarter" <<'\n';
    for(const auto& course : all_courses)
    {
        if (course.quarter != "null")
        {
            ofs << course.title << ',' << course.number_of_units << ',' << course.quarter << '\n';
        }
    }
    ofs << std::flush;
    auto it = all_courses.begin();
    while (it != all_courses.end())
    {
        if (it -> quarter != "null")
            it = all_courses.erase(it); 
        else
        it++;
    }
    ofs.close();
}

void write_courses_not_offered(std::vector<Courses>& unlisted_courses)
{
    std::ofstream ofs(CSV_NOT_OFFERED);
    ofs << "Title,Number of Units,Quarter" <<'\n';
    for(const auto& course : unlisted_courses)
    {
        ofs << course.title << ',' << course.number_of_units << ',' << course.quarter << '\n';
    }
    ofs << std::flush;

    ofs.close();
}

int main()
{
    std::vector<Courses> courses ;
    parse_csv(CSV , courses);
    //write_courses_offered(courses);
    //write_courses_not_offered(courses);
    return 0;
}