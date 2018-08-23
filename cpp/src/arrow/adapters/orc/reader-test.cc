// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include <cstdint>
#include <limits>
#include <new>

#include <gtest/gtest.h>

#include "adapter.h"
#include "arrow/io/file.h"
#include "arrow/test-util.h"

namespace arrow {

namespace adapters {

namespace orc {

TEST(adapter, EmptyFile) {
  const std::string path = "TestOrcFile.emptyFile.orc";
  std::shared_ptr<io::ReadableFile> file;
  ASSERT_OK(io::ReadableFile::Open(path, &file));

  std::unique_ptr<ORCFileReader> reader;
  ASSERT_OK(ORCFileReader::Open(file, default_memory_pool(), &reader));

  std::shared_ptr<Table> table;
  ASSERT_OK(reader->Read(&table));

}

}  // namespace orc

}  // namespace adapters

}  // namespace arrow
