// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

TStack<char, 100> stack1;
TStack<int, 100> stack2;

std::string infx2pstfx(std::string inf) {
  std::string res = "";
        for (int i = 0; i < inf.length(); i++) {
            if (inf[i] == '(') {
                stack1.push(inf[i]);
            } else if (inf[i] == ')') {
                while (!stack1.isEmpty() && stack1.top() != '(') {
                    res += stack1.pop();
                }
                res += " ";
                stack1.pop();
            } else if (inf[i] >= '0' && inf[i] <= '9') {
                while (i < inf.length() && (inf[i] >= '0' && inf[i] <= '9')) {
                    res += inf[i];
                    i++;
                }
                res += " ";
                i--;
            } else if (strchr("(+-*/^", inf[i])) {
                char op = inf[i];
                while (!stack1.isEmpty()) {
                    int priorS = 0;
                    switch (stack1.top()) {
                        case '+': priorS = 1;
                        case '-': priorS = 1;
                        case '*': priorS = 2;
                        case '/': priorS = 2;
                    }
                    int priorOp = 0;
                    switch (op) {
                        case '+': priorOp = 1;
                        case '-': priorOp = 1;
                        case '*': priorOp = 2;
                        case '/': priorOp = 2;
                    }
                    if (!(priorS >= priorOp)) {
                        break;
                    }
                    res = res + stack1.pop() + " ";
                }
                stack1.push(op);
            }
        }
        while (!stack1.isEmpty()) {
            res += stack1.pop();
        }
        return res;
}

int eval(std::string pref) {
  std::string number = "";
    for (int i = 0; i < post.length(); i++) {
        if (pref[i] >= '0' && pref[i] <= '9') {
            number += pref[i];
        } else if (pref[i] == ' ') {
            if (number != "") {
                stack2.push(std::stoi(number));
                number = "";
            }
        } else if (pref[i] == '+' || pref[i] == '-'
            || pref[i] == '*' || pref[i] == '/') {
            switch (pref[i]) {
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
