/* Copyright 2017 - 2021 R. Thomas
 * Copyright 2017 - 2021 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIEF_MACHO_PARSER_H_
#define LIEF_MACHO_PARSER_H_
#include <string>
#include <vector>
#include <memory>

#include "LIEF/types.hpp"
#include "LIEF/visibility.h"

#include "LIEF/Abstract/Parser.hpp"

#include "LIEF/MachO/ParserConfig.hpp"

namespace LIEF {
class VectorStream;

namespace MachO {
class Binary;
class FatBinary;

class LIEF_API Parser : public LIEF::Parser {
  public:
  Parser& operator=(const Parser& copy) = delete;
  Parser(const Parser& copy)            = delete;

  ~Parser(void);

  static std::unique_ptr<FatBinary> parse(const std::string& filename, const ParserConfig& conf = ParserConfig::deep());
  static std::unique_ptr<FatBinary> parse(const std::vector<uint8_t>& data, const std::string& name = "", const ParserConfig& conf = ParserConfig::deep());

  private:
  Parser(const std::string& file, const ParserConfig& conf);
  Parser(const std::vector<uint8_t>& data, const std::string& name, const ParserConfig& conf);
  Parser(void);

  void build(void);
  void build_fat(void);

  std::unique_ptr<VectorStream> stream_;
  std::vector<Binary*>          binaries_;
  ParserConfig                  config_;
};
}
}
#endif
