
#include "Reader.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

Entropy::Reader::Reader(const int & value) : value(value)
{



}


Entropy::Reader::Reader(int&& value) : value(value)
{

  std::cout << "TEST" << std::endl;

}

int Entropy::Reader::get_position(std::vector<std::string> results, std::string name)
{
 
  std::vector<std::string>::iterator it = std::find(results.begin(), results.end(), name);
  
  if (it == results.end())
  {
    return -1;
  }
  else
  {
    return std::distance(results.begin(), it);
  }
  
}



void Entropy::Reader:: parse()
{


  std::ifstream infile("/home/franco/Programming/Project-Entropy/EntropyCalculator/EntropyCalculator/data/sample-pdsi.dump");
  std::string line;
  bool flag = false;
  int x_num = -1;
  int y_num = -1;
  int z_num = -1;

  while (std::getline(infile, line))
  {

    if (line.empty())
    {
      continue;
    }

    std::istringstream iss(line);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>());

    if (results.front() == items)
    {
      if (results.at(1) == atoms)
      {
        flag = true;
      }
    }

    if (flag)
    {
      
      std::cout << "TEST" << std::endl;

    }


    /*
    if (results.front() == items && results.at(1) == atoms)
    {
      flag = true
      std::vector<std::string>::iterator x_it = std::find(results.begin(), results.end(), x);
      std::vector<std::string>::iterator y_it = std::find(results.begin(), results.end(), y);
      std::vector<std::string>::iterator z_it = std::find(results.begin(), results.end(), z);
      if (x_it != results.end())
      {
        x_num = std::distance(results.begin(), x_it);
      }
      if (y_it != results.end())
      {
        y_num = std::distance(results.begin(), y_it);
      }
      if (z_it != results.end())
      {
        z_num = std::distance(results.begin(), z_it);
      }
    } 
    */


  }

}
