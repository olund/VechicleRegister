#ifndef READER_H
#define READER_H

#include <string>

class IReader
{
private:
  std::string filename;

public:
  Reader();
  Reader(const std::string filename);
  virtual ~Reader();

  virtual List<T> load() = 0;
  virtual bool save() = 0;

};

Reader::Reader() {
    this->filename = "data.txt";
}

Reader::Reader(const std::string filename) {
  this->filename = filename;
}

Reader::~Reader() {
}

#endif // READER_H
