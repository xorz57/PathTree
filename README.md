# PathTree

[![Build](https://github.com/xorz57/PathTree/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/PathTree/actions/workflows/Build.yml)

## Example

```cpp
#include "PathTree/PathTree.hpp"

int main() {
    path_tree_t path_tree;
    path_tree.add_path("/bin");
    path_tree.add_path("/etc");
    path_tree.add_path("/sbin");
    path_tree.add_path("/usr/bin");
    path_tree.add_path("/usr/include");
    path_tree.add_path("/usr/lib");
    path_tree.add_path("/usr/local/bin");
    path_tree.add_path("/usr/local/lib");
    path_tree.add_path("/usr/local/man");
    path_tree.add_path("/usr/local/sbin");
    path_tree.add_path("/usr/local/share");
    path_tree.add_path("/usr/share/man");
    path_tree.add_path("/var/cache");
    path_tree.add_path("/var/lib");
    path_tree.add_path("/var/lock");
    path_tree.add_path("/var/log");
    path_tree.add_path("/var/opt");
    path_tree.add_path("/var/spool/cron");
    path_tree.add_path("/var/spool/cups");
    path_tree.add_path("/var/spool/mail");
    path_tree.add_path("/var/spool/tmp");
    path_tree.add_path("/dev");
    path_tree.add_path("/home");
    path_tree.add_path("/lib");
    path_tree.add_path("/mnt");
    path_tree.add_path("/opt");
    path_tree.add_path("/proc");
    path_tree.add_path("/root");
    path_tree.show();
    std::cout << std::boolalpha << path_tree.contains_path("/") << std::endl;
    std::cout << std::boolalpha << path_tree.contains_path("/usr") << std::endl;
    std::cout << std::boolalpha << path_tree.contains_path("/usr/local") << std::endl;
    std::cout << std::boolalpha << path_tree.contains_path("/usr/local/bin") << std::endl;
    return 0;
}
```

## Output

```console
/
  bin
  etc
  sbin
  usr
    bin
    include
    lib
    local
      bin
      lib
      man
      sbin
      share
    share
      man
  var
    cache
    lib
    lock
    log
    opt
    spool
      cron
      cups
      mail
      tmp
  dev
  home
  lib
  mnt
  opt
  proc
  root
true
true
true
true
```

## How to Build

#### Linux & macOS

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

git clone https://github.com/xorz57/PathTree.git
cd PathTree
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

#### Windows

```powershell
git clone https://github.com/microsoft/vcpkg.git C:/vcpkg
C:/vcpkg/bootstrap-vcpkg.bat
C:/vcpkg/vcpkg.exe integrate install

git clone https://github.com/xorz57/PathTree.git
cd PathTree
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```
