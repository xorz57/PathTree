/*
    MIT License

    Copyright (c) 2024 George Fotopoulos

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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
