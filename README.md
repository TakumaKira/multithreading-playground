# Multithreading Playgroud

This repository is for testing the following article:

[NoMultithreading and Mutexes Made Simple](https://code.likeagirl.io/multithreading-and-mutexes-made-simple-8087404053cd)

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

```bash
g++ d-use_mutex.cpp -o out_d-use_mutex -pthread && ./out_d-use_mutex
```

```bash
g++ e-use_lock_guard.cpp -o out_e-use_lock_guard -pthread && ./out_e-use_lock_guard
```