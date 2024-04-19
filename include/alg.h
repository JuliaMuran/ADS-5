// Copyright 2021 NNTU-CS
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_
#include <iostream>
#include "tstack.h"
#include <string>
using namespace std;

std::string infx2pstfx(std::string inf);

int eval(string post) {
    std::string number = "";
    for (int i = 0; i < post.length(); i++) {
        if (post[i] >= '0' && post[i] <= '9') {
            number += post[i];
        } else if (post[i] == ' ') {
            if (number != "") {
                stack2.push(std::stoi(number));
                number = "";
            }
        } else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/') {
            switch (post[i]) {
                case '*': {
                    stack2.push(stack2.pop() * stack2.pop());
                    break;
                }
                case '/': {
                    stack2.push(stack2.pop() / stack2.pop());
                    break;
                }
                case '+': {
                    stack2.push(stack2.pop() + stack2.pop());
                    break;
                }
                case '-': {
                    int left = stack2.pop();
                    int right = stack2.pop();
                    stack2.push(right - left);
                    break;
                }
            }
        }
    }
    return stack2.pop();
}
#endif  // INCLUDE_ALG_H_
