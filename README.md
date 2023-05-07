# gossiping

C++ implementation of the first [distributed systems challenge](https://fly.io/dist-sys/). The task is simply to answer with the same message (i.e., echo).

## Setup

Package management is done using [conan](https://docs.conan.io/2.0/tutorial/consuming_packages/build_simple_cmake_project.html). To install all dependencies, run:

```
conan install . --output-folder=build --build=missing
```

## Testing

To test the implementation, compile the binary and run:

```
./maelstrom test -w echo --bin $GOSSIP_BIN --node-count 1 --time-limit 10
```
