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

#ifndef SRC_INFRA_API_H_
#define SRC_INFRA_API_H_

#ifdef __cplusplus
extern "C" {
#endif

int x(int y);

typedef void *Foo;
Foo FooInit(void);
void FooFree(Foo);
void FooBar(Foo);

typedef void *CommandEventStore;
CommandEventStore InitCommandEventStore(const char *config);
void DeinitCommandEventStore(CommandEventStore raftCommandEventStore);

#ifdef __cplusplus
}
#endif

#endif  // SRC_INFRA_API_H_
