# PathTree

[![Build](https://github.com/xorz57/PathTree/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/PathTree/actions/workflows/Build.yml)

## Example

```cpp
#include "PathTree/PathTree.hpp"

int main() {
    path_tree_t path_tree;
    path_tree.addPath("/bin");
    path_tree.addPath("/etc");
    path_tree.addPath("/sbin");
    path_tree.addPath("/usr/bin");
    path_tree.addPath("/usr/include");
    path_tree.addPath("/usr/lib");
    path_tree.addPath("/usr/local/bin");
    path_tree.addPath("/usr/local/lib");
    path_tree.addPath("/usr/local/man");
    path_tree.addPath("/usr/local/sbin");
    path_tree.addPath("/usr/local/share");
    path_tree.addPath("/usr/share/man");
    path_tree.addPath("/var/cache");
    path_tree.addPath("/var/lib");
    path_tree.addPath("/var/lock");
    path_tree.addPath("/var/log");
    path_tree.addPath("/var/opt");
    path_tree.addPath("/var/spool/cron");
    path_tree.addPath("/var/spool/cups");
    path_tree.addPath("/var/spool/mail");
    path_tree.addPath("/var/spool/tmp");
    path_tree.addPath("/dev");
    path_tree.addPath("/home");
    path_tree.addPath("/lib");
    path_tree.addPath("/mnt");
    path_tree.addPath("/opt");
    path_tree.addPath("/proc");
    path_tree.addPath("/root");
    path_tree.show();
    std::cout << std::boolalpha << path_tree.containsPath("/") << std::endl;
    std::cout << std::boolalpha << path_tree.containsPath("/usr") << std::endl;
    std::cout << std::boolalpha << path_tree.containsPath("/usr/local") << std::endl;
    std::cout << std::boolalpha << path_tree.containsPath("/usr/local/bin") << std::endl;
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
