# PathTree

[![Build](https://github.com/xorz57/PathTree/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/PathTree/actions/workflows/Build.yml)

## Example

```cpp
#include "PathTree/PathTree.hpp"

int main() {
    PathTree pathTree;
    pathTree.addPath("/bin");
    pathTree.addPath("/etc");
    pathTree.addPath("/sbin");
    pathTree.addPath("/usr/bin");
    pathTree.addPath("/usr/include");
    pathTree.addPath("/usr/lib");
    pathTree.addPath("/usr/local/bin");
    pathTree.addPath("/usr/local/lib");
    pathTree.addPath("/usr/local/man");
    pathTree.addPath("/usr/local/sbin");
    pathTree.addPath("/usr/local/share");
    pathTree.addPath("/usr/share/man");
    pathTree.addPath("/var/cache");
    pathTree.addPath("/var/lib");
    pathTree.addPath("/var/lock");
    pathTree.addPath("/var/log");
    pathTree.addPath("/var/opt");
    pathTree.addPath("/var/spool/cron");
    pathTree.addPath("/var/spool/cups");
    pathTree.addPath("/var/spool/mail");
    pathTree.addPath("/var/spool/tmp");
    pathTree.addPath("/dev");
    pathTree.addPath("/home");
    pathTree.addPath("/lib");
    pathTree.addPath("/mnt");
    pathTree.addPath("/opt");
    pathTree.addPath("/proc");
    pathTree.addPath("/root");
    pathTree.show();
    std::cout << std::boolalpha << pathTree.containsPath("/") << std::endl;
    std::cout << std::boolalpha << pathTree.containsPath("/usr") << std::endl;
    std::cout << std::boolalpha << pathTree.containsPath("/usr/local") << std::endl;
    std::cout << std::boolalpha << pathTree.containsPath("/usr/local/bin") << std::endl;
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
