# Multithreading Playgroud

This repository is for testing the following article:

[NoMultithreading and Mutexes Made Simple](https://code.likeagirl.io/multithreading-and-mutexes-made-simple-8087404053cd)

I modified a bit to make the problem clearer.

## Setup

This repository recommand to run with VSCode's `Dev Container` feature to avoid environmental issues, especially if you are not using Linux computer.

1. Setup and run [Docker](https://www.docker.com/)
2. Clone this repository by git URL in Dev Container using VSCode's `Dev Containers: Clone Repository in Container Volume` command.

## Commands to run samples

```bash
g++ a-single_threading.cpp -o out_a-single_threading && ./out_a-single_threading
```

```bash
g++ b-multi_threading.cpp -o out_b-multi_threading -pthread && ./out_b-multi_threading
```

```bash
g++ c-problematic_multithreading.cpp -o out_c-problematic_multithreading -pthread && ./out_c-problematic_multithreading
```

By running above several times, you'll observe 2nd "Current total: ..." message comes in BEFORE getting 1st "Finished Problematic Section for n: ..." message.

```bash
g++ d-use_mutex.cpp -o out_d-use_mutex -pthread && ./out_d-use_mutex
```

```bash
g++ e-use_lock_guard.cpp -o out_e-use_lock_guard -pthread && ./out_e-use_lock_guard
```

By using locks, you'll never obvserve the problem observed in no-lock example.