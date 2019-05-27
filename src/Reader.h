

// Include guards can be set with pragma once too instead of ifndef
#pragma once

#include <string>
#include <vector>

namespace Entropy {


  class Reader
  {

    private:

      const std::string items = "ITEM:";

      const std::string atoms = "ATOMS";

      const std::string x = "x";

      const std::string y = "y";

      const std::string z = "z";

      const int & value;

      int get_position(std::vector<std::string> results, std::string name);

    public:

      Reader(const int & value);

      Reader(int&& value);

      void parse();


  };


}
