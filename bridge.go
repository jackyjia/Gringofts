package main

import "fmt"

// #cgo LDFLAGS: build/libinfra.a
// #cgo LDFLAGS: build/libinfra_raft.a
// #cgo LDFLAGS: build/libinfra_monitor.a
// #cgo LDFLAGS: build/libinfra_util.a
// #cgo LDFLAGS: build/libstore_proto_library.a
// #cgo LDFLAGS: build/liblib_inih.a
// #cgo LDFLAGS: -lboost_system -lboost_iostreams
// #cgo LDFLAGS: -lcrypto
// #cgo LDFLAGS: -lstdc++
// #include "src/infra/api.h"
import "C"

// func main() {
//   fmt.Printf("Invoking c library...\n")
//   C.x(10)
//   fmt.Printf("Done\n")
// }

// type GoFoo struct {
// 	foo C.Foo
// }
//
// func New() GoFoo {
// 	var ret GoFoo
// 	ret.foo = C.FooInit()
// 	return ret
// }
// func (f GoFoo) Free() {
// 	C.FooFree(f.foo)
// }
// func (f GoFoo) Bar() {
// 	C.FooBar(f.foo)
// }

type CommandEventStore struct {
    commandEventStore C.CommandEventStore
}

func New() CommandEventStore {
    var ret CommandEventStore
    ret.commandEventStore = C.InitCommandEventStore("conf/raft_0.ini")
    return ret
}

func (commandEventStore CommandEventStore) Free() {
    C.DeinitCommandEventStore(commandEventStore.CommandEventStore)
}

func main() {
    fmt.Printf("Invoking c library...\n")
// 	foo := New()
// 	foo.Bar()
// 	foo.Free()
    commandEventStore := New()
    commandEventStore.Free()
	fmt.Printf("Done\n")
}
