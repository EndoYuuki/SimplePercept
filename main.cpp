#include <iostream>
#include <utility>
#include <vector>
#include "simple_percept.hpp"

int main(int argc, char* argv[])
{
  SimplePercept<double> sp(3, 0.1);
  std::vector<std::vector<double>> train = {{1, 1, 1}, {0,1, 1}, {1,0,1}, {0,0,1}};
  std::vector<double> y = {1, 0, 0, 0};

  for (int i = 0; i < 100; i++)
  {
    for (unsigned int j = 0; j < train.size(); j++)
    {
      sp.train(train[j], y[j]);
    }
  }

  for (unsigned int j = 0; j < train.size(); j++)
  {
    std::cout << sp.feedforward(train[j]) << std::endl;
  }

  return 0;
}
