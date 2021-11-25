#include <string>
#include <algorithm>


void removeFile(const std::string& file_name) {
  const char* cstr = file_name.c_str();
  std::remove(cstr);
}
