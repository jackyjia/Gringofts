/************************************************************************
Copyright 2019-2020 eBay Inc.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    https://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**************************************************************************/

#include "api.h"
#include "apiClasses.cpp"

#include <stdio.h>
#include <iostream>

#include "es/store/RaftCommandEventStore.h"
#include "raft/RaftBuilder.h"

int x(int y) {
  std::cout << "hello" << std::endl;
  printf("Hello World\n");
  return y;
}

using gringofts::cxxFoo;

Foo FooInit() {
  cxxFoo *ret = new cxxFoo(1);
  return (void *) ret;
}

void FooFree(Foo f) {
  cxxFoo *foo = (cxxFoo *) f;
  delete foo;
}

void FooBar(Foo f) {
  cxxFoo *foo = (cxxFoo *) f;
  foo->Bar();
}

CommandEventStore InitCommandEventStore(const char *configPath) {
  INIReader reader(configPath);
  if (reader.ParseError() < 0) {
    SPDLOG_WARN("Cannot load config file {}, exiting", configPath);
    exit(-1);
  }

  auto crypto = std::make_shared<gringofts::CryptoUtil>();
  crypto->init(reader);

  auto raftImpl = gringofts::raft::buildRaftImpl(configPath);
  auto commandEventStore = new gringofts::RaftCommandEventStore(raftImpl, crypto);

  return (void *) commandEventStore;
}

void DeinitCommandEventStore(CommandEventStore raftCommandEventStore) {
  gringofts::RaftCommandEventStore *commandEventStore = (gringofts::RaftCommandEventStore *) raftCommandEventStore;
  delete commandEventStore;
}