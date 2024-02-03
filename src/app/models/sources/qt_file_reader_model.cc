#include "../headers/main_model.h"

namespace s21 {

Scene QtFileReader::ReadFile(const std::string &path) {
  std::filesystem::path filePath(path);

  if (!std::filesystem::exists(filePath))
    throw std::logic_error("file doesn't exist");

  if (filePath.extension().string() != ".obj")
    throw std::logic_error("file doesn't obj");

  this->scene_.clear();

  std::ifstream file;
  file.open(path);

  if (!file.is_open()) throw std::logic_error("file hasn't opened");

  std::string str_tmp;
  try {
    while (std::getline(file, str_tmp)) {
      if (!LineParser(str_tmp)) continue;
    }
  } catch (const std::exception &e) {
    file.close();
    throw;
  }
  file.close();

  return this->scene_;
}

bool QtFileReader::LineParser(const std::string &line) {
  switch (IsType(line)) {
    case 1:
      return (!VertexLineValidator(line) || !VertexParser(line)) ? false : true;
    case 2:
      return (!FasetLineValidator(line) || !FasetParser(line)) ? false : true;
  }
  return false;
};

bool QtFileReader::VertexLineValidator(const std::string &line) {
  for (size_t i = 0; i < line.length(); i++) {
    if (line[i] != ' ' && line[i] != '.' && line[i] != 'v' && line[i] != '-' &&
        !std::isdigit(line[i]) &&
        std::count(line.cbegin(), line.cend(), 'v') != 1) {
      return false;
    }
  }
  return true;
}

bool QtFileReader::FasetLineValidator(const std::string &line) {
  for (size_t i = 0; i < line.length(); i++) {
    if (line[i] != ' ' && line[i] != '.' && line[i] != 'f' && line[i] != '/' &&
        line[i] != '-' && !std::isdigit(line[i]) &&
        std::count(line.cbegin(), line.cend(), 'f') != 1) {
      return false;
    }
  }
  return true;
}

bool QtFileReader::VertexParser(const std::string &line) {
  std::string str_tmp;
  std::vector<double> point3D;
  double tmp = 0.0;

  for (size_t i = 0; i < line.length(); i++) {
    if (std::isdigit(line[i]) || line[i] == '-') {
      tmp = VertexToDouble(line, i);
      point3D.push_back(tmp);
    }
  }

  if (point3D.size() != 3)
    throw std::logic_error("vertex parser error: point3D != 3");

  this->scene_.GetFigure().PushVertex(point3D[0], point3D[1], point3D[2]);
  return true;
}

bool QtFileReader::FasetParser(const std::string &line) {
  std::string str_tmp;
  std::vector<int> fasets;
  std::vector<std::string> str = SplitStringBySpace(line);

  auto it = str.begin();
  ++it;
  for (; it != str.end(); it++) {
    fasets.push_back(std::round(FasetToDouble(it->data())));
  }

  this->scene_.GetFigure().PushEdge(fasets);

  return true;
}

std::vector<std::string> QtFileReader::SplitStringBySpace(
    const std::string &str) {
  std::vector<std::string> result;
  std::stringstream ss(str);
  std::string token;

  while (ss >> token) {
    result.push_back(token);
  }

  return result;
}

double QtFileReader::VertexToDouble(const std::string &line,
                                    size_t &begin_position) {
  std::string str_xyz;
  str_xyz.push_back(line[begin_position]);
  size_t i;

  for (i = begin_position + 1; i < line.length(); i++) {
    if (line[i] == ' ' || line[i] == '\r')
      break;
    else if (std::isdigit(line[i]) || line[i] == '.')
      str_xyz.push_back(line[i]);
    else if (line[i] == 'e') {
      if (line[i + 1] != '-' && line[i + 1] != '+')
        throw std::logic_error("Invalid argument");
      str_xyz.push_back(line[i + 1]);
      i++;
    } else
      throw std::logic_error("Invalid argument");
  }
  begin_position = i;
  return std::stod(str_xyz);
}

double QtFileReader::FasetToDouble(const std::string &subline) {
  auto tmp = subline.find_first_of('/');

  if (tmp == std::string::npos) {
    return std::stod(subline);
  } else {
    std::string numberString = subline.substr(0, tmp);
    return std::stod(numberString);
  }
}

int QtFileReader::IsType(const std::string &line) {
  if (line[0] == 'v' && line[1] == ' ')
    return 1;
  else if (line[0] == 'f' && line[1] == ' ')
    return 2;
  else
    return 0;
}

}  // namespace s21
