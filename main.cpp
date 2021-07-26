#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

bool conversionPart(std::string part) {
  if (part.size() < 1 || part.size() > 3) 
    return false;
  if (part.size() != 1 && part[0] == '0') 
    return false;
  int value = -1;
  try {
    value = stoi(part);
  } catch (std::invalid_argument) {
    return false;
  }
  return value >= 0 && value <= 255;
}

bool checkIpAddress(std::string ip) {
  std::istringstream issIp(ip);
  std::string part;
  int partCount = 0;
  while (std::getline(issIp, part, '.') && conversionPart(part)){
    partCount++;
  }
  return partCount == 4 && ip[ip.size() - 1] != '.';
}

void test() {
  std::vector<std::string> correctIp =  {
                                        "127.0.0.1",
                                        "255.255.255.255",
                                        "1.2.3.4",
                                        "55.77.213.101"
                                        };
  std::vector<std::string> incorrectIp = {
                                        "255.256.257.258",
                                        "0.55.33.22.",
                                        "10.00.000.0",
                                        "23.055.255.033",
                                        "65.123..9", 
                                        "a.b.c.d"
                                        };
  std::cout << "Test correst ip" << std::endl;
  for(int i = 0; i < correctIp.size(); ++i){
    int countDot = count(correctIp[i].begin(), correctIp[i].end(), '.');
    std::cout << (countDot != 3 ? "No\n" : (checkIpAddress(correctIp[i]) ? "Yes\n" : "No\n"));
  }
  std::cout << "\nTest incorrest ip" << std::endl;
  for(int i = 0; i < incorrectIp.size(); ++i){
    int countDot = count(incorrectIp[i].begin(), incorrectIp[i].end(), '.');
    std::cout << (countDot != 3 ? "No\n" : (checkIpAddress(incorrectIp[i]) ? "Yes\n" : "No\n"));
  }
  
}

int main() {
  //test();
  std::string ipAddress;
  std::getline(std::cin, ipAddress);
  int countDot = count(ipAddress.begin(), ipAddress.end(), '.');
  std::cout << (countDot != 3 ? "No" : (checkIpAddress(ipAddress) ? "Yes" : "No"));
}