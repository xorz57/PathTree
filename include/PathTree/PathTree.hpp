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

#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class path_tree_t {
public:
    path_tree_t() = default;

    void addPath(const std::string &path) {
        add_path_helper(mRoot, path);
    }

    void removePath(const std::string &path) {
        remove_path_helper(mRoot, path);
    }

    bool containsPath(const std::string &path) const {
        return contains_path_helper(mRoot, path);
    }

    void clear() {
        clear_helper(mRoot);
    }

    void show() const {
        show(mRoot, 0);
    }

private:
    struct Node {
        explicit Node(const std::string &name) : name(name) {}
        std::vector<std::shared_ptr<Node>> children;
        std::string name;
    };

    void add_path_helper(const std::shared_ptr<Node> &root, const std::string &path) const {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<Node> current = root;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                        current->children.begin(),
                        current->children.end(),
                        [&](const std::shared_ptr<Node> &child) { return child->name == name; });
                if (it == current->children.end()) {
                    auto component = std::make_shared<Node>(name);
                    current->children.push_back(component);
                    current = component;
                } else {
                    current = *it;
                }
            }
        }
    }

    void remove_path_helper(const std::shared_ptr<Node> &root, const std::string &path) {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<Node> current = root;
        std::shared_ptr<Node> parent = nullptr;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                        current->children.begin(),
                        current->children.end(),
                        [&](const std::shared_ptr<Node> &child) { return child->name == name; });
                if (it != current->children.end()) {
                    parent = current;
                    current = *it;
                } else {
                    return;
                }
            }
        }
        parent->children.erase(
                std::remove_if(
                        parent->children.begin(),
                        parent->children.end(),
                        [&](const std::shared_ptr<Node> &child) { return child->name == current->name; }),
                parent->children.end());
    }

    bool contains_path_helper(const std::shared_ptr<Node> &root, const std::string &path) const {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<Node> current = root;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                        current->children.begin(),
                        current->children.end(),
                        [&](const std::shared_ptr<Node> &child) { return child->name == name; });
                if (it == current->children.end()) {
                    return false;
                } else {
                    current = *it;
                }
            }
        }
        return true;
    }

    void clear_helper(std::shared_ptr<Node> root) const {
        root->children.clear();
    }

    void show(std::shared_ptr<Node> root, unsigned int depth) const {
        for (unsigned int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << root->name << std::endl;
        for (const std::shared_ptr<Node> &child: root->children) {
            show(child, depth + 1);
        }
    }

    std::shared_ptr<Node> mRoot = std::make_shared<Node>("/");
};
