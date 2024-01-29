#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class PathTree {
public:
    PathTree() = default;

    void addPath(const std::string &path) {
        addPathHelper(mRoot, path);
    }

    void removePath(const std::string &path) {
        removePathHelper(mRoot, path);
    }

    bool containsPath(const std::string &path) const {
        return containsPathHelper(mRoot, path);
    }

    void clear() {
        clearHelper(mRoot);
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

    void addPathHelper(const std::shared_ptr<Node> &root, const std::string &path) const {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<Node> current = root;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                    current->children.begin(),
                    current->children.end(),
                    [&](const std::shared_ptr<Node> &child){ return child->name == name; }
                );
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

    void removePathHelper(const std::shared_ptr<Node> &root, const std::string &path) {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<Node> current = root;
        std::shared_ptr<Node> parent = nullptr;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                    current->children.begin(),
                    current->children.end(),
                    [&](const std::shared_ptr<Node> &child){ return child->name == name; }
                );
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
                [&](const std::shared_ptr<Node> &child){ return child->name == current->name; }),
                parent->children.end()
            );
    }

    bool containsPathHelper(const std::shared_ptr<Node> &root, const std::string &path) const {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<Node> current = root;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                    current->children.begin(),
                    current->children.end(),
                    [&](const std::shared_ptr<Node> &child){ return child->name == name; }
                );
                if (it == current->children.end()) {
                    return false;
                } else {
                    current = *it;
                }
            }
        }
        return true;
    }

    void clearHelper(std::shared_ptr<Node> root) const {
        root->children.clear();
    }

    void show(std::shared_ptr<Node> root, unsigned int depth) const {
        for (unsigned int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << root->name << std::endl;
        for (const std::shared_ptr<Node> &child : root->children) {
            show(child, depth + 1);
        }
    }

    std::shared_ptr<Node> mRoot = std::make_shared<Node>("/");
};
