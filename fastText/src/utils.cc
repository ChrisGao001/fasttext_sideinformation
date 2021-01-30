/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "utils.h"

#include <ios>

using std::string;
using std::vector;

namespace fasttext {

namespace utils {

int64_t size(std::ifstream& ifs) {
  ifs.seekg(std::streamoff(0), std::ios::end);
  return ifs.tellg();
}

void seek(std::ifstream& ifs, int64_t pos) {
  ifs.clear();
  ifs.seekg(std::streampos(pos));
}

void split(std::string &text, std::vector<std::string> &items, char delim='#') {
    items.clear();
    ssize_t start = 0;
    ssize_t pos = 0;
    string item;
    while (start < text.size()) {
        pos = text.find(delim, start);
        if (pos == string::npos) {
            item = text.substr(start);
            items.push_back(item);
            break;
        }
        item = text.substr(start, pos - start);
        items.push_back(item);
        start = pos + 1;
    }
}

} // namespace utils

} // namespace fasttext
