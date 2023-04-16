#include <iostream>
#include <fstream>

int main() {
  std::cout << "Enter file path: " << std::endl;
  std::string path; // C:\Users\User\Desktop\AMarkets.png
  std::cin >> path;
  if (path.substr(path.length() - 4, -1) != ".png") {
    std::cout << "This file is not <PNG>!";
    return 1;
  }
  std::ifstream temp;
  temp.open(path, std::ios::binary);
  if (!temp.is_open()) {
    std::cout << "Error opening file!";
    return 2;
  }
  int n = 4;
  char *buffer = new char[n + 1];
  buffer[n] = 0;
  temp.seekg(1);
  temp.read(buffer, n);
  std::string str = buffer;
  if (str[0] == 'P' && str[1] == 'N' && str[2] == 'G') {
    std::cout << "You opened <PNG> file" << std::endl;
  } else{
    std::cout << "This file is not <PNG>!";
  }
  delete[] buffer;
  temp.close();
  return 0;
}
