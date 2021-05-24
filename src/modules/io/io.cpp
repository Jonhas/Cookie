#include "io.hpp"

std::string read_file(const char *filename) {
  FILE *fp = fopen((const char *)filename, "r");
  if (!fp) {
    perror("Invalid file read");
    fclose(fp);
  }
  fseek(fp, 0, SEEK_END);
  const size_t length = ftell(fp);
  char *where = new char[length];
  rewind(fp);
  fread(where, sizeof(char), length, fp);
  auto out = std::string(where);
  delete[] where;
  out.erase(std::remove_if(out.begin(), out.end(), cookie::token::is_ascii),
            out.end());
  fclose(fp);
  return out;
}
